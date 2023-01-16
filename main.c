//github:https://github.com/mohammad-hajiebrahimi

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//define files name
#define USER_FILE_ADDRESS "accounts.txt"
#define POSTS_FILE_ADDRESS "posts.txt"

//Data structure and linked list of post with property of name post_ID number of likes and text
typedef struct Post{
    char name[20];
    int post_ID;
    int likes;
    char* text;
    struct Post *next;
} Post;

//Data structure and linked list of  users with property of name password posts numbers and user numbers
typedef struct User{
    char name[20];
    char password[20];
    int posts_num;
    int users_num;
    struct User *next;
} User;


// declearing header files
#include "Signup.h"
#include "Login.h"
#include "Posts.h"
#include "Info.h"
#include "File.h"




int main(){
    //create head of linked list of users and posts
    User* user_head=NULL;
    user_head = (User*)malloc(sizeof(User));
    user_head->users_num=0;
    Post* post_head=NULL;
    post_head = (Post*)malloc(sizeof(Post));
    User* login_user=NULL;
    printf("wellcome to UT-Tooti\n");
    //start command line
    while(1){
        char s[70];
        //give command from user
        scanf("%s", s);
        if(!strcmp(s,"signup\0")){
            //go to signup founction and do works
            Signup(user_head, login_user);
            user_head->users_num++;

        }
        else if(!strcmp(s,"login\0")){
            //go to login founction and do works
            login_user = Login(user_head);
        }
        else if(!strcmp(s,"post\0")){
            //go to Add_Post founction and do works
            //printf("%s\n", s);
            Add_Post(post_head, login_user);
        }
        else if(!strcmp(s,"like\0")){
            //go to Like founction and do works
            Like(post_head, login_user);
        }
        else if(!strcmp(s,"logout\0")){
            if(login_user == NULL){
                printf("login first please\n");
            }
            else{
                printf("logout from %s\n", login_user->name);
                login_user=NULL;
            }
        }
        else if(!strcmp(s,"delete\0")){
            //go to Delete founction and do works
            Delete(post_head);
        }
        else if(!strcmp(s,"info\0")){
            //go to Info founction and do works
            Info(login_user, post_head, 1);
        }
        else if(!strcmp(s,"find_user\0")){
            //go to Find_User founction and do works
            Find_User(user_head, post_head);
        }
        else if(!strcmp(s,"bye\0")){
            //if user command to quit break the loop
            printf("goodbye!!\n");
            break;
        }
        else if(!strcmp(s,"clear\0")){
            system("clear");
        }
        else{
            //if user give wrong command do best act
            printf("wrong command!!\n");
        }
        //go to save founction and save users, posts info in files
        save(user_head,post_head);
    }
}
