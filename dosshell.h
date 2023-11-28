// DOSshell.h
#ifndef DOSSHELL_H
#define DOSSHELL_H

#include "tree.h"

class DOSshell {
private:
    TreeNode* root;  
    TreeNode* currentDirectory;  

public:
    DOSshell() : root(nullptr), currentDirectory(nullptr) {}

    void init() {
        root = new TreeNode("maindir");
        currentDirectory = root;

        TreeNode* s1Dir = new TreeNode("s1_dir");
        TreeNode* s2Dir = new TreeNode("s2dir");
        TreeNode* s11Dir = new TreeNode("s11_dir");

        root->addChild(s1Dir);
        root->addChild(s2Dir);
        s2Dir->addChild(s11Dir);

        s1Dir->addChild(new TreeNode("si.txt"));
        s11Dir->addChild(new TreeNode("tex.txt"));
        s2Dir->addChild(new TreeNode("t11.txt"));

        root->addChild(new TreeNode("newfile"));
    }

    void displayTree() const {
        currentDirectory->display();
        cout << "--------------------------------" << endl;
    }
    void displaycurrentdir() const {

    }
};

#endif  // DOSSHELL_H
