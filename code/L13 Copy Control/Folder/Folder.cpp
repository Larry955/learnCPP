#include<utility>

#include<iostream>
using std::cerr; using std::endl;

#include<set>
using std::set;

#include<string>
using std::string;

#include"Folder.h"

void swap(Message &lhs, Message &rhs)
{
	using std::swap; 

	//remove pointers to each Message from original respective Folder
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	//swap the contents and Folder pointer sets
	swap(lhs.folders, rhs.folders);		//use swap(set&,set&)
	swap(lhs.contents, rhs.contents);	//use swap(string&,string&)

	//add pointers to each Message to their new respective Folders
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Folder::Folder(Folder &&f)
{
	move_Messages(&f);		//make each message points to this Folder
}

Folder& Folder::operator=(Folder &&f)
{
	if (this != &f){
		remove_from_Msgs();		//remove this Folder from the current msgs
		move_Messages(&f);		//make each message points to this Folder
	}
	return *this;
}

void Folder::move_Messages(Folder *f)
{
	msgs = std::move(f->msgs);		//move the set from f to this Folder
	f->msgs.clear();				//ensure that destroying f is harmless

	for (auto m : msgs){		//for each message in this Folder
		m->remFldr(f);			//remove the pointer to the old Folder 
		m->addFldr(this);		//insert pointer to this Folder
	}
}

Message::Message(Message &&m) :contents(std::move(m.contents))
{
	move_Folders(&m);		//moves folders and updates the Folder pointers
}

Message::Message(const Message &m) :
contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);		//add this Message to the Folders that point to m
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs){		//direct check for self-assignment
		remove_from_Folders();
		contents = std::move(rhs.contents);		//move assignment
		move_Folders(&rhs);		//reset the Folders to point to rhis message
	}
	return *this;
}

Message& Message::operator=(const Message &rhs)
{
	//handle self-assignment by removing pointers before inserting
	remove_from_Folders();		//update existing Folders
	contents = rhs.contents;	//copy Messages from rhs
	folders = rhs.folders;		//copy folders from rhs
	add_to_Folders(rhs);		//add this Message to those Folders
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

//move the Folder pointers from m to this Message
void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);	//use set move assignment
	for (auto f : folders){		//for each Folder
		f->remMsg(m);		//remove the old Message from the Folder
		f->addMsg(m);		//add this Message to that Folder
	}
	m->folders.clear();		//ensure that destroyging this m is harmless
}

//add this message to the Folder that points to m
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)	//for each message that holds m
		f->addMsg(this);		//add a pointer to this message to that Folder
}

//remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
	for (auto f : folders)		//for each pointer in folders
		f->remMsg(this);		//remove this Message from that Folder
	folders.clear();			//no Folder points to this Message
}


void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);		//add this Folder to each Message
}

Folder::Folder(const Folder &f) :msgs(f.msgs)
{
	add_to_Messages(f);		//add this Folder to each Message in f.msgs
}

Folder& Folder::operator=(const Folder &f)
{
	remove_from_Msgs();		//remove this folder from each Message in msgs
	msgs = f.msgs;		//copy the set of Messages from f
	add_to_Messages(f);		//add this folder to each Message in msgs
	return *this;
}

Folder::~Folder()
{
	remove_from_Msgs();
}

void Folder::remove_from_Msgs()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}

void Message::save(Folder &f)
{
	folders.insert(&f);		//add the given folder to the list of Folders
	f.addMsg(this);		//add this Message to f's set of Messages
}

void Message::remove(Folder &f)
{
	folders.erase(&f);		//take the given folder out of our this of Folders
	f.remMsg(this);		//remove this Message to f's set of Messages
}

void Folder::save(Message &m)
{
	//add m and add this folder to m's set of Folders 
	msgs.insert(&m);
	m.addFldr(this);
}

void Folder::remove(Message &m)
{
	msgs.erase(&m);
	m.remFldr(this);
}

void Folder::debug_print()
{
	cerr << "Folder contains " << msgs.size() << " messages" << endl;
	int ctr = 1;
	for (auto m : msgs)
		cerr << "message " << ctr++ << ": \n\t" << m->contents << endl;
}

void Message::debug_print()
{
	cerr << "Message:\n\t" << contents << endl;
	cerr << "Appears in " << folders.size() << endl;
}