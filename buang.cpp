    //insert into an empty list
    if(head == NULL){
        head = newptr;
    }
    else{
        // a loop to move prev and cur along the list and stop at appropriate place
        // to insert a new element
        while(crptr != NULL && newptr->number > crptr->number){
            prptr = crptr;
            crptr = crptr->next;
        }
        //insert in front of the list
        if(prptr == NULL){
            newptr->next = crptr;
            head = newptr;
        }
        else {
        //coding to insert at the middle or the end of the list
        newptr->next = crptr;
        prptr->next = newptr;
        }
    }
    
     for ( int i=0; i<10 ; i++)
    {
        Beep(2000,500);
        cout<<l; 
         }
