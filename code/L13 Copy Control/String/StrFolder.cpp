#include<utility>

#include<iostream>
using std::cerr; using std::endl;

#include<set>
using std::set;

#include"StrFolder.h"

void swap(Message &lhs, Message &rhs)
{
	using std::swap;

	//remove pointers to each message from their (original) resepective Folders
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	//swap the contents and Folder pointer sets
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	//add pointers to each Message to their (new) respective Folders
}

Folder::Folder(Folder &&f)
{
	move_Message(&f);	//make each Message point to this Folder
}

Folder& Folder::operator=(Folder &&rhs)
{
	if (this != &rhs){		//check for self-assignment
		remove_from_Messages();	//remove this Folder from current msgs
		move_Message(&rhs);		//make each message points to this Folder
	}
	return *this;
}
 
void Folder::move_Message(Folder *f)
{
	msgs = std::move(f->msgs);	//move the set from f to this folder
	f->msgs.clear();		//ensure destroying f is harmless
	for (auto m : msgs){
		m->remFldr(f);	//remove the pointer to	the old Folder
		m->addFldr(this);	//insert pointer to this Folder
	}

}

Message::Message(Message &&m) :contents(std::move(m.contents))
{
	move_Folders(&m);	//moves the folders and update the Folder pointers
}

Message::Message(const Message &m) : 
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);	//add this Message to the Folders that point to m
}

Message& Message::operator=(const Message &rhs){
	//handle self-assignment by removing pointers before inserting them
	remove_from_Folders();	//update existing folders
	contents = rhs.contents;	//copy Message contents from rhs
	folders = rhs.folders;	//copy Folder pointers from rhs
	add_to_Folders(rhs);	//add this Message to those Folders

	return *this;
}

Message& Message::operator=(Message &&rhs)
{
	if (this != &rhs){
		remove_from_Folders();
		contents = std::move(rhs.contents);	//move assignment
		add_to_Folders(rhs);	//reset the Folders to point to this Message
	}
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
	for (auto f : folders){	//for each Folder
		f->remMsg(m);	//remove the old Message from the Folder
		f->addMsg(this);	//add this Message to that Folder
	}
	m->folders.clear();		//ensure that destroying m is harmless
}

//add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)	//for each Folder that holds m
		f->addMsg(this);	//add a pointer to this Message to that Folder
}

//remove this Message from corresponding Folders
void Message::remove_from_Folders()
{
	for (auto m : folders)	//for each pointer in folders
		m->remMsg(this);	//remove this Message from that Folder
	folders.clear();	//no folder that points to this Message
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);	//add this Folder to each Message
}

Folder::Folder(const Folder &f) :msgs(f.msgs)
{
	add_to_Messages(f);	//add this folder to each Message in f.msgs
}

Folder& Folder::operator=(const Folder &f)
{
	remove_from_Messages();	//remove this Folder from each Message in msgs
	msgs = f.msgs;	//copy the set of Message from f
	add_to_Messages(f);	//add this Folder to each Message in msgs
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::remove_from_Messages()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}

void Message::save(Folder &f)
{
	folders.insert(&f);	//add the given folder to our list of Folders
	f.addMsg(this);	//add this Message to f's set of Messages
}

void Message::remove(Folder &f)
{
	folders.erase(&f);	//take the given Folder out of our list of Folders
	f.remMsg(this);	//remove this Message from f's set of Messages
}

void Folder::save(Message &m)
{
	msgs.insert(&m);	//add the given message to our list of Messages
	m.addFldr(this);	//add this Folder to m's set of Folders
}

void Folder::remove(Message &m)
{
	msgs.erase(&m);	//take the given Message out of our list of Messages
	m.remFldr(this);	//remove this Folder from m's set of Folders
}

void Folder::debug_print()
{
	cerr << "Folder contains " << msgs.size() << " messages" << endl;
	int ctr = 1;
	for (auto m : msgs)
		cerr << "Message " << ++ctr << ":\n\t" << m->contents << endl;
}

void Message::debug_print()
{
	cerr << "Message: " << contents
		<< " Appears in " << folders.size() << " Folders" << endl;
}
