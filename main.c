#include <stdio.h>
#include <string.h>

struct book
{
 int an;
 char *title;
 char *author;
 int issued;
};


void display(struct book *b, int number_of_books)
{
    for (int i=0; i<number_of_books; i++){
        printf("Accession number-\t%d\nBook-\t%s\nAuthor-\t%s\n",(b+i)->an,(b+i)->title,(b+i)->author);
        if((b+i)->issued == 0)
        {
            printf("Issued-\tNo\n");
        }
        else
        {
            printf("Issued-\tYes\n");
        }
    }
}

void add(struct book *b, int number_of_books)
{
 //Do yourself
    int n;
    char title[30],author[30];
    printf("Enter number of books to be added:");
    scanf("%d",&n);
    for (int i=number_of_books; i<number_of_books+n; i++){


        (b+i)->an=i;
        printf("Accession number is:%d\n",(b+i)->an);
        printf("Enter the title:");
        gets(title);
        strcpy((b+i)->title,title);
        printf("Enter the author name:");
        gets(author);
        strcpy((b+i)->author,author);
        (b+i)->issued=0;
    }



 //issued will be 0 by defalut
}

//passing array

void book_by_author(struct book *b,int number_of_books,char auth[])
{
 int i;
 for(i=0;i<number_of_books;i++)
 {
   if(strcmp((b+i)->author,auth)==0)
   {
     printf("Accession number-\t%d\nBook-\t%s\nAuthor-\t%s\n",(b+i)->an,(b+i)->title,(b+i)->author);
   }
 }
}

void book_by_title(struct book *b, int number_of_books, char t[])
{
 //do it yourself
 int i;
 for(i=0;i<number_of_books;i++)
 {
   if(strcmp((b+i)->title,t)==0)
   {
     printf("Accession number-\t%d\nBook-\t%s\nAuthor-\t%s\n",(b+i)->an,(b+i)->title,(b+i)->author);
   }
 }
}

void issue_a_book(struct book *b)
{
 b->issued =1;
}

int number_of_books (struct book *b){
    int number_of_books;
    for (int i=0; (b+i)->title!=NULL; i++){
        number_of_books=i+1;
    }

    return number_of_books;
}

int main()
{



    struct book *mybookPtr= NULL;
    //mybookPtr= (struct book*)malloc (100* sizeof(struct book));
    struct book mybook[100]={0};
    mybookPtr=&mybook;

    mybook[0].an=0;
    mybook[0].title="part1";
    mybook[0].author="author1";
    mybook[0].issued=0;

    mybook[1].an=1;
    mybook[1].title="part2";
    mybook[1].author="author2";
    mybook[1].issued=0;

    mybook[2].an=2;
    mybook[2].title="part3";
    mybook[2].author="author3";
    mybook[2].issued=0;

    mybook[3].an=3;
    mybook[3].title="part4";
    mybook[3].author="author4";
    mybook[3].issued=0;
    int accession_no;
    int numberOfBook = number_of_books(mybookPtr);
    printf("Number of books: %d\n",numberOfBook);
/*

 (mybookPtr+0)->an=1;
 (mybookPtr+0)->title="part1";
 (mybookPtr+0)->author="author1";
 (mybookPtr+0)->title=0;

 (mybookPtr+1)->an=2;
 (mybookPtr+1)->title="part2";
 (mybookPtr+1)->author="author2";
 (mybookPtr+1)->title=0;

 (mybookPtr+2)->an=3;
 (mybookPtr+2)->title="part3";
 (mybookPtr+2)->author="author3";
 (mybookPtr+2)->title=0;

 (mybookPtr+3)->an=4;
 (mybookPtr+3)->title="part4";
 (mybookPtr+3)->author="author4";
 (mybookPtr+3)->title=0;

 (mybookPtr+4)->an=5;
 (mybookPtr+4)->title="part5";
 (mybookPtr+4)->author="author5";
 (mybookPtr+4)->title=0;

 (mybookPtr+5)->an=6;
 (mybookPtr+5)->title="part6";
 (mybookPtr+5)->author="author6";
 (mybookPtr+5)->title=0;*/


// printf("\n %d",mybook[1].issued);
 display(mybookPtr,numberOfBook);
 char author[30],title[30];
 printf("Enter author name:");
 gets(author);
 //printf("/n %s",author);
 book_by_author(mybookPtr,numberOfBook,author);
 printf("\nEnter title:");
 gets(title);
 book_by_title(mybookPtr,numberOfBook,title);
 printf("Enter accession number:");
 scanf("%d",&accession_no);
 issue_a_book(mybookPtr+accession_no);
 display(mybookPtr,numberOfBook);
 //printf("\n %s",mybook[4].title);
 add(mybookPtr,numberOfBook);
 display(mybookPtr,numberOfBook);

 free(mybookPtr);
 return 0;
}
