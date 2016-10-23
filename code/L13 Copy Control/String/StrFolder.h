#ifndef	STRFOLDER_H
#define STRFOLDER_H

#include"String.h"
#include<set>

class Folder;

class Message{
	friend void swap(Message&, Message&);
	friend class Folder;

public:
	//folders is implicitly initialized to the empty set 
	explicit Message(const String &str = " "):
		contents(str){}

	//copy control to manage pointers to this Message
	Message(const Message&);				//copy constructor
	Message& operator=(const Message&);		//copy assignment operator
	~Message();								//destructor
	Message(Message&&);						//move constructor
	Message& operator=(Message&&);			//move assignment operator

	//add this Message to the specified Folder's set of messages
	void save(Folder&);
	//remove this Message from the specified Folder's set of messages
	void remove(Folder&);
	void debug_print();		//print contents and its list of folders
							//printing each Folder as well
private:
	String contents;		//actual message text
	std::set<Folder*>folders;		//Folders that have this Message

	//utility functions used by copy constructor,assignment,and destructor
	//add this Message to the Folders that point to the parameter
	void add_to_Folders(const Message&);
	void move_Folders(Message*);
	//remove this Message from every Folder in folders
	void remove_from_Folders();

	//used by Folder class to add self to this Message's set of Folders
	void addFldr(Folder *f){ folders.insert(f); }
	void remFldr(Folder *f){ folders.erase(f); }

};

void swap(Message&, Message&);

class Folder{
	friend void swap(Message&, Message&);
	friend class Message;

public:
	Folder() = default;
	
	Folder(const Folder&);				//add new folder to each Message in msgs
	Folder& operator=(const Folder&);	//delete from lhs messages
										//add Folder to rhs message

	Folder(Folder &&);					//move Messages to this Folder
	Folder& operator=(Folder&&);		//delete from lhs messages
										//add Folder to rhs messages

	~Folder();							//remove self from Messages in msgs

	void save(Message&);				//add this message to folders
	void remove(Message&);				//remove this message from folders

	void debug_print();					//print contents and its list of Folders
private:
	std::set<Message*>msgs;				//messages in this folder

	void add_to_Messages(const Folder&);//add this folder to each messages
	void move_Message(Folder*);			//move message pointers to point to this folder

	void remove_from_Messages();		//remove this folder from each message
	void addMsg(Message *m){ msgs.insert(m); }
	void remMsg(Message *m){ msgs.erase(m); }
};
#endif