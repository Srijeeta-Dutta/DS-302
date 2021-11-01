void display_forward()
{
    Node *tptr = start;
    printf("\nDATA forward:\n");
    while (tptr)
    {
        printf("->%d", tptr->info);
        tptr = tptr->rptr;
    }
}