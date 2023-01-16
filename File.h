int size(char* s)
{
    int cnt=0;
    while(s[cnt]!='\0')
    {
        cnt++;
    }
    return cnt;
}

void save(User* user_head, Post* post_head){
    //open files
    FILE* user_file = fopen(USER_FILE_ADDRESS, "w");
    FILE* post_file = fopen(POSTS_FILE_ADDRESS, "w");
    //write every things in users linked list in user_file
    while(user_head->next!=NULL){
        fwrite(user_head->next->name, 1, size(user_head->next->name), user_file);
        fwrite(" ",1,1,user_file);
        fwrite(user_head->next->password, 1, size(user_head->next->password), user_file);
        fwrite(" ",1,1,user_file);
        fprintf(user_file, "%d", user_head->next->posts_num);
        fwrite("\n",1,1,user_file);
        user_head = user_head->next;
    }
    fclose(user_file);
    //write every things in posts linked list in post_file
    while(post_head->next!=NULL){
        fwrite(post_head->next->text, 1, size(post_head->next->text), post_file);
        fwrite(" ",1,1,post_file);
        fwrite(post_head->next->name, 1, size(post_head->next->name), post_file);
        fwrite(" ",1,1,post_file);
        fprintf(post_file, "%d", post_head->next->likes);
        fwrite("\n",1,1,post_file);
        post_head = post_head->next;
    }
    fclose(post_file);
}
