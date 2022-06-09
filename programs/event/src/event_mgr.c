#include <stdio.h>
#include <stdlib.h>
#include <module.h>

struct event_reg{
    int moduleno;
    int event;
    fnptr cb;
    struct event_reg *next;
};

struct event_reg *head = NULL;

void register_event(int moduleno, int event,fnptr cb){
    struct event_reg *temp=(struct event_reg*)malloc(sizeof(struct event_reg));
    temp->moduleno = moduleno;
    temp->event = event;
    temp->cb = cb;
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head = temp;
}
int perform_event(int eventno){
    int flag=0;
    struct event_reg *temp=head;
    while(temp)
    {
        if(CHECK_BIT(temp->event,eventno)){
            temp->cb(eventno);
            flag=1;
        }
        temp=temp->next;
    }
    return flag;
}
void trigger_event(){
    int eventno;
    printf("Enter event to be performed: ");
    scanf("%d",&eventno);
    if(!perform_event(eventno))
        printf("Invalid event");
}
void unregister_event(){
    struct event_reg *cur = head;
    struct event_reg *temp;
    while(cur){
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    head = NULL;
    printf("Unregistered the events!");
}
