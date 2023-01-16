void Signup(User* user_head, User* login_user){
    //if user is login print please logout first
    if(login_user!=NULL){
        printf("please logout first\n");
    }
    //get name and password of new user and add it to end of users linked list like this
    else{
        char name[20], password[20];
        scanf("%s %s", name, password);
        User* new = (User*)malloc(sizeof(User));
        strcpy(new->name, name);
        strcpy(new->password, password);
        while(user_head->next!=NULL)user_head = user_head->next;
        user_head->next = new;
    }
}
