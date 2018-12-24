#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H

#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include "node.h"
#include "file.h"
#include "link.h"
#include "folder.h"

class NodeBuilder
{
public:
    NodeBuilder(){}
    virtual ~NodeBuilder(){}

    void build(char * path)
    {
        struct stat st;
        if (lstat(path, &st) == 0)
        {
            if (S_ISREG(st.st_mode))
            {
                _root = new File(path);
            }
            else if (S_ISLNK(st.st_mode))
            {
                _root = new Link(path);
            }
            else if (S_ISDIR(st.st_mode))
            {
                _root = new Folder(path);
                DIR * dir = opendir(path);

                if (dir == nullptr)
                    throw std::string("open folder error");

                struct dirent *entry = nullptr;
                while ((entry = readdir(dir)) != nullptr)
                {
                    if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..")
                    {
                        NodeBuilder nb2;
                        std::string pathName = std::string(path) + "/" + std::string(entry->d_name);
                        char * c_pathName = &pathName[0u];
                        nb2.build(c_pathName);
                        _root->add(nb2.getRoot());
                    }
                }
            }
        }
    }

    Node * getRoot()
    {
        return _root;
    }

private:
    Node *_root;
};

#endif
