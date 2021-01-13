#include<iostream>
#include<set>
#include<string>
using namespace std;

class Folder;

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const string &str=""):contents(str){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void addFolder(Folder*);
    void remFolder(Folder*);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};


class Folder{
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs);
public:
    Folder()=default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    
private:
    set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*);
    void add_to_Message(const Folder&);
    void remove_from_Message();
};


void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder* f){
    folders.insert(f);
}

void Message::remFolder(Folder* f){
    folders.erase(f);
}

void Message::add_to_Folders(const Message &m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

Message::Message(const Message &m):contents(m.contents), folders(m.folders){
    add_to_Folders(m);
}

void Message::remove_from_Folders(){
    for(auto f : folders){
        f->remMsg(this);
    }
}

Message::~Message(){
    remove_from_Folders();
}

Message& Message:: operator=(const Message &rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs){
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}


void Folder::addMsg(Message* m){
    messages.insert(m);
}

void Folder::remMsg(Message* m){
    messages.erase(m);
}

void Folder::add_to_Message(const Folder& f){
    for(auto m: messages){
        m->addFolder(this);
    }
}
Folder :: Folder(const Folder &f):messages(f.messages){
    add_to_Message(f);
}

void Folder::remove_from_Message(){
    for(auto m : messages){
        m->remFolder(this);
    }
}

Folder& Folder::operator=(const Folder &rhs){
    remove_from_Message();
    messages = rhs.messages;
    add_to_Message(rhs);
    return *this;
}

Folder::~Folder(){
    remove_from_Message();
}

void swap(Folder &lhs, Folder &rhs) 
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.messages, rhs.messages);
    
    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

int main(){
    return 0;
}