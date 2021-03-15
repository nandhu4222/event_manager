#include <stdio.h>
#include <module.h>

int main(){
    int i,j,event_count,choice;
    
    printf("EVENT MANAGER TASK\nEnter the number of events: ");
    scanf("%d",&event_count);
    if(!event_count)
        return -1;
    module_init(event_count);
    printf("\nPerforming events (Enter 1 to continue 0 to exit)");

    getchoice:
        printf("\n\nEnter choice:");
        scanf("%d",&choice);
    while(choice){
        trigger_event();
        goto getchoice;  
    }
    module_deinit();
}

