void Info(User* login_user,Post* post_head, int is_login){
    //if no user is login
    if(login_user == NULL){
        printf("This user does not exist\n");
    }
    else{
        //if user is login print name and password
        int flag=0;
        printf("username:%s\n", login_user->name);
        if(is_login) printf("password:%s\n", login_user->password);
        Post* post = post_head;
        //go to posts linked list and print every posts of this user
        while(1){
            if(flag){
                break;
            }
            if(post->next==NULL)break;
            post = post->next;
            if(!strcmp(post->name, login_user->name)){
                printf("post_ID:%d\n", post->post_ID);
                printf("text:%s\n", post->text);
                printf("likes:%d\n\n", post->likes);
            }
        }
    }
}
void Find_User(User* user_head, Post* post_head){
    User* find=NULL;
    char name[20];
    int flag=0;
    //give name of user from karbar
    scanf("%s", name);
    //search in users linked list to find this user
    while(1){
        if(!strcmp(name, user_head->name)){
            find = user_head;
            break;
        }
        if(flag){
            break;
        }
        if(user_head->next==NULL){
            flag =1;
        }
        user_head = user_head->next;
    }
    //if dont find this user print this
    if(find == NULL){
        printf("This user does not exist\n");

    }
    else{
        Info(find,post_head, 0);
    }
}
