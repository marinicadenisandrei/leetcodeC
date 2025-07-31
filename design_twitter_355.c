/* Leetcode - 355. Design Twitter (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20

void reset ();
void green ();
void yellow ();
void red ();

struct user
{
    int id;
    int tweets[ARRAY_SIZE];
    int tweetsSize;

    int followers[ARRAY_SIZE];
    int followersSize;
};

struct user userList[ARRAY_SIZE] = {};
int userListSize = 0;

void postTweet(int id, int tweet)
{
    userList[userListSize].id = id;
    userList[userListSize].tweets[userList[userListSize].tweetsSize++] = tweet;
    userListSize++;
}

void getNewsFeed(int id)
{
    printf("[");

    for (int i = 0; i < userListSize; i++)
    {
        if (userList[i].id == id)
        {
            for (int j = 0; j < userList[i].tweetsSize; j++)
            {
                printf("%i%s", userList[i].tweets[j], ((j < userList[i].tweetsSize - 1) ? ", " : ((userList[i].followersSize > 0) ? ", " : "")));
            }
            
            for (int j = 0; j < userList[i].followersSize; j++)
            {
                for (int k = 0; k <= userListSize; k++)
                {
                    if (userList[k].id == userList[i].followers[j])
                    {
                        for (int l = 0; l < userList[k].tweetsSize; l++)
                        {
                            printf("%i%s", userList[k].tweets[l], ((k < userList[k].tweetsSize - 1) ? ", " : ""));
                        }
                    }
                }
            }

            break;
        }
    }

    printf("] ");
}

void follow(int id1, int id2)
{
    for (int i = 0; i < userListSize; i++)
    {
        if (userList[i].id == id1)
        {
            userList[i].followers[userList[i].followersSize++] = id2;
            break;
        }
    }
}

void unfollow(int id1, int id2)
{
    for (int i = 0; i < userListSize; i++)
    {
        if (userList[i].id == id1)
        {
            for (int j = 0; j < userList[i].followersSize; j++)
            {
                if (userList[i].followers[j] == id2)
                {
                    for (int k = j; k < userList[i].followersSize - 1; k++)
                    {
                        userList[i].followers[k] = userList[i].followers[k + 1];
                    }
                            
                    break;
                }
            }

            userList[i].followersSize--;
            
            break;
        }
    }
}

int main()
{
    yellow();

    printf("Leetcode - 355. Design Twitter (C language) - Medium\n");

    green();

    printf("Test 1: ");

    reset();

    postTweet(1,5);
    getNewsFeed(1);
    follow(1,2);
    postTweet(2,6);
    getNewsFeed(1);
    unfollow(1,2);
    getNewsFeed(1);

    printf("| ");

    green();

    printf("Passed\n");

    reset();
}

void reset () {
    printf("\033[1;0m");
  }
  
  void green () {
    printf("\033[1;32m");
  }
  
  void yellow () {
    printf("\033[1;33m");
  }
  
  void red () {
    printf("\033[1;31m");
  }
  
  