// tree.h
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TreeNode {
public:
    string name;
    vector<TreeNode*> children;

    TreeNode(const string& n) : name(n) {}

    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }

    void display(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << name << endl;

        for (const TreeNode* child : children) {
            child->display(depth + 1);
        }
    }

    TreeNode* findChild(const string& childName) const {
        for (TreeNode* child : children) {
            if (child->name == childName) {
                return child;
            }
        }
        return nullptr;
    }

    void getAttributes(const string& filename) const {
        TreeNode* fileNode = findChild(filename);
        if (fileNode) {
            cout << "Attributes for file '" << filename << "':" << endl;
            cout << "Size: N/A, Type: N/A, Last Modified: N/A" << endl;
        }
        else {
            cout << "File '" << filename << "' not found." << endl;
        }
    }

    void getCurrentDirectory() const {
        cout << name<<" d:\>";
    }

    TreeNode* moveToParent() const {
        return getParent();
    }

    TreeNode* moveToRoot() const {
        return getRoot();
    }

private:
    TreeNode* getParent() const {
        if (name == "maindir") {
            return nullptr;
        }

        return findParent(getRoot(), this);
    }

    TreeNode* getRoot() const {
        const TreeNode* currentNode = this;
        while (currentNode->name != "maindir") {
            currentNode = getParent();
        }

        return const_cast<TreeNode*>(currentNode);
    }

    TreeNode* findParent(TreeNode* currentNode, const TreeNode* childNode) const {
        for (TreeNode* child : currentNode->children) {
            if (child == childNode) {
                return currentNode;
            }

            TreeNode* foundParent = findParent(child, childNode);
            if (foundParent) {
                return foundParent;
            }
        }

        return nullptr;
    }
};

#endif  // TREE_H
