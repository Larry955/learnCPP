#ifndef FOLDER_H
#define FOLDER_H

#include<string>
using std::string;

#include<set>
using std::set;

class Folder;

class Message{
	friend void swap(Message&, Message&);
	friend class Folder;

public:
	explicit Message(const string& str = ""):
		contents(str){ }

	//copy control to manage pointers to this Message
	Message(const Message&);				//copy constructor
	Message& operator=(const Message&);		//copy assignment
	~Message();								//destructor

	Message(Message&&);						//move constructor
	Message& operator=(Message&&);			//move assignment
	
	//add/remove this Message from the specified Folder's set of message
	void save(Folder&);
	void remove(Folder&);
	
	void debug_print();	//print contents and its list of folders
						//printing each folder as well
private:
	string contents;		//actual message txt
	set<Folder*>folders;	//Folders that have this message

	//utility functions that used by copy constructor,assignment and destructor
	//add this message to the Folder that points to the parameter
	void add_to_Folders(const Message&);
	void move_Folders(Message*);
	//remove this message from every folder that contatins this message
	void remove_from_Folders();

	//used by Folder class to add self to this message's set of Folder's
	void addFldr(Folder *f){folders.insert(f); }
	void remFldr(Folder *f){folders.erase(f); }
};

//declaration of swap should be in the same header as Message itself
void swap(Message&, Message&);

class Folder{
	friend void swap(Message&, Message&);
	friend class Message;

public:
	Folder() = default;		//default constructor
	
	Folder(const Folder&);				//add new folder to each Message in msgs
	Folder& operator=(const Folder&);	//delete folder from lhs messages
										//add folder to rhs messages
	~Folder();		//remove messages from Message in msgs

	Folder(Folder&&);				//move messages to this Folder
	Folder& operator=(Folder&&);	//delete Folder from lhs messages
									//add folder to rhs message

	void save(Message&);		//add this message to folder
	void remove(Message&);		//remove this message from folder

	void debug_print();			//print contents and it's list of Folder
private:
	set<Message*>msgs;		//messages in this Folder

	void add_to_Messages(const Folder&);		//add this folder to each message
	void remove_from_Msgs();					//remove this folder from message
	void addMsg(Message *m){ msgs.insert(m); }
	void remMsg(Message *m){ msgs.erase(m); }
	void move_Messages(Folder*);				//move Message pointers to point to this Folder
};
#endif