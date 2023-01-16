User* Login(User* user_head){
    char name[20], password[20];
    int flag=0;
    //give name and password from user
    scanf("%s %s", name, password);
    User *login_user,*curr = user_head->next;
    while(1){
        //if name and password  is correct
        if(!strcmp(name, curr->name) && !strcmp(password, curr->password)){
            printf("login successfully!!\n");
            return curr;
        }
        //if name is correct and password is incorrect
        if(!strcmp(name, curr->name) && strcmp(password, curr->password)){
            printf("the password is incorrect try again\n");
            return NULL;
        }
        //if no user like this found
        if(flag){
            printf("Don't find this user please signup\n");
            return NULL;
        }
        if(curr->next==NULL){
            flag =1;
        }
        curr = curr->next;
    }
}
