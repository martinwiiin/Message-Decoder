#include <iostream>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
#include "prioQueue.h"
#include <queue>
#include "Functions.h"
#include "BST.h"
using namespace std;

int main(int argc, char*argv[]){
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    //ifstream input("input2.txt");
    //ofstream output("output1.txt");

    BST tree;
    queue<string> mQ;
    prioQueue pQ;
    string in = "";
    string traverse = "";

    while(getline(input, in)){
        if(in == "Inorder" || in == "Preorder" || in == "Postorder"){
            traverse = in;
        }
        else{
            string temp = in.substr(0, in.find("("));
            int prio = stoi(in.substr(in.find("(") + 1, in.find(")")));
            //cout << temp << " " << prio << endl;
            pQ.enqueue(temp, prio);
        }
    }
    
    
    //pQ.print();

    while(!pQ.isEmpty()){
        string temp = pQ.getHead()->data;
        string command = temp.substr(0,temp.find(":"));
        if(command == "DECODE"){
            string message = temp.substr(temp.find("[")+1);
            message = message.substr(0, message.find("]"));
            //cout << message << endl;
            mQ.push(message);
        }
        else if(command == "REPLACE"){
            if(mQ.empty()){
                cout << "ERROR: No message to decode" << endl;
            }
            else{
                string message = mQ.front();
                mQ.pop();
                char a = temp[temp.find("[")+1];
                char b = temp[temp.find(",")+1];
                message = Replace(message, a, b);
                //cout << message << endl;
                mQ.push(message);
            }
        }
        else if(command == "ADD"){
            if(mQ.empty()){
                cout << "ERROR: No message to decode" << endl;
            }
            else{
                string message = mQ.front();
                mQ.pop();
                char a = temp[temp.find("[")+1];
                char b = temp[temp.find(",")+1];
                message = add(message, a, b);
                //cout << message << endl;
                mQ.push(message);
            }
        }
        else if(command == "REMOVE"){
            if(mQ.empty()){
                cout << "ERROR: No message to decode" << endl;
            }
            else{
                string message = mQ.front();
                mQ.pop();
                char a = temp[temp.find("[")+1];
                message = Remove(message, a);
                //cout << message << endl;
                mQ.push(message);
            }
        }
        else if(command == "SWAP"){
            if(mQ.empty()){
                cout << "ERROR: No message to decode" << endl;
            }
            else{
                string message = mQ.front();
                mQ.pop();
                char a = temp[temp.find("[")+1];
                char b = temp[temp.find(",")+1];
                message = Swap(message, a, b);
                //cout << message << endl;
                mQ.push(message);
            }
        }
        else if(command == "BST"){
            if(mQ.empty()){
                cout << "ERROR: No message in queue" << endl;
            }
            else{
                string message = mQ.front();
                mQ.pop();
                tree.insert(message);  
            }
        }
        

       
        //cout << temp << endl;
        pQ.dequeue();
    }

    
    if(traverse == "Inorder"){
        tree.printInorder(output,tree.getRoot());
    }
    else if(traverse == "Preorder"){
        tree.printPreorder(output,tree.getRoot());
    }
    else if(traverse == "Postorder"){
        tree.printPostorder(output,tree.getRoot());
    }

    


    //tree.insert("this message has been decoded");
    //tree.printInorder(tree.getRoot());
    
    //tree.print();

    //cout << Replace("slsphant", 's', 'e') << endl;
    //cout << add("bann", 'n', 'a') << endl;
    //cout << Remove("mevssvavge", 'v') << endl;
    //cout << Swap("bnanan", 'n','a') << endl;
    return 0;

}