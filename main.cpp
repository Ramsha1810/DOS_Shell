#include "tree.h"

int main() {
    // Create the directory tree
    TreeNode root("maindir");
    TreeNode s1Dir("s1_dir");
    TreeNode s2Dir("s2dir");
    TreeNode s11Dir("s11_dir");
    TreeNode newFile("newfile");

    root.addChild(&s1Dir);
    root.addChild(&s2Dir);
    s2Dir.addChild(&s11Dir);
    root.addChild(&newFile);
    
    do {
        string userInput;
        root.getCurrentDirectory();
        getline(cin, userInput);

        if (userInput == "exit") {
            break;  
        }

        if (userInput.substr(0, 7) == "attrib ") {
            std::string filename = userInput.substr(7);
            root.getAttributes(filename);
        }
        else if (userInput == "cd") {
            root.getCurrentDirectory();
        }
        else if (userInput == "cd.") {
            root.getCurrentDirectory();
        }
        else if (userInput == "cd..") {
            root = *root.moveToParent();  
            root.getCurrentDirectory();
        }
        else if (userInput == "cd\\") {
            root = *root.moveToRoot(); 
            root.getCurrentDirectory();
        }
        else {
            cout << "Invalid command. Try again or enter 'exit' to exit." <<endl;
        }

    } while (true);

    return 0;
}
