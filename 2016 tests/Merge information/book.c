#include "book.h"
#include <string.h>
#include <stdlib.h>
BookInfoList returnlist;

int cmp (const void *A, const void *B) {
	BookInfo *a = (BookInfo *)A;
	BookInfo *b = (BookInfo *)B;
	int x = strcmp(a->book_title,b->book_title);
	if (x != 0)
		return x;
	else {
		return (a->date - b->date);
	}
}

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]) {
	int checkedsell[MAXN];
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (strcmp(authorArr[i].book_title, sellingArr[j].book_title) == 0) {
				returnlist.books[count].selling = sellingArr[j].selling;
				returnlist.books[count].date = sellingArr[j].date;
				strcpy(returnlist.books[count].book_title, authorArr[i].book_title);
				strcpy(returnlist.books[count].author, authorArr[i].author);
				count++;		
			}
		}
	}
	qsort(returnlist.books, count, sizeof(BookInfo), cmp);
	returnlist.num = count;
	return returnlist;
}