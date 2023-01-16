void Add_Post(Post* post_head, User* login_user){
    char s[200],tmp;
    int i=0;
    //give sep to correct input
    scanf("%c", &tmp);
    //give input until see endl
    for(;;i++){
        scanf("%c", &s[i]);
        if(s[i]=='\n')break;
    }
    s[i]='\0';
    //create a dynamic array to save text in it
    char* text = (char*)malloc(i*sizeof(char));
    strcpy(text, s);
    printf("%s\n",text);
    //if no user login
    if(login_user == NULL){
        printf("login first\n");
    }
    else{
        // create new post and set information of it
        Post* new = (Post*)malloc(sizeof(Post));
        strcpy(new->name, login_user->name);
        login_user->posts_num++;
        new->post_ID = login_user->posts_num;
        new->likes=0;
        new->next = NULL;
        new->text = text;
        //add new post to end of linked list of posts
        while(post_head->next!=NULL)post_head=post_head->next;
        post_head->next = new;
        printf("post_ID:%d\n", new->post_ID);
        printf("text:%s\n", new->text);
        printf("likes:%d\n", new->likes);
    }
}
int Like(Post* post_head, User* login_user){
    char name[20];
    int post_ID;
    scanf("%s %d", name, &post_ID);
    //login user cant like own post
    if(!strcmp(name, login_user->name)){
        printf("You can't like your posts\n");
        return 0;
    }
    //search in posts linked list and find this post and like it
    while(1){
        if(!strcmp(post_head->name, name) && post_ID==post_head->post_ID){
            post_head->likes++;
            printf("post %d likes\n", post_ID);
            return 1;
        }
        if(post_head->next==NULL) break;
        post_head = post_head->next;
    }
    printf("This post does not exist\n");
    return 0;

}
int Delete(Post* post_head){
    int post_ID,flag=0;
    scanf("%d",&post_ID);
    while(1){
        if(post_head->next==NULL){
            break;
        }
        if(post_head->next->post_ID == post_ID){
            free(post_head->next);
            post_head->next = post_head->next->next;
            printf("Delete successfully!!\n");
            return 1;
        }
        post_head = post_head->next;
    }
    printf("This post does not exist\n");
}
