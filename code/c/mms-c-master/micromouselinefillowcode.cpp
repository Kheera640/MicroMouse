void setwall(int dir_facing,int dir_wall)
{
    dir_facing=(dir_facing+4)%4;
    dir_wall=(dir_wall+4)%4;

    //update valuse of m[][] 
    if(N && N)
    if(N && E)
    if(E && E)
    if(E && S)
    if(S && S)
    if(S && W)
    if(W && W)
    if(W && N)
}

void IR()
{
    //fire left ir
    //fire forward ir
    //fire right ir

    next_array[0]=value of left ir;
    next_array[1]=value of front ir;
    next_array[2]=value of right ir;

    if(next_array[0])
    {
        wall_dir=dir_facing-1;
        setwall(dir_faing,dir_wall);
    }
    if(next_array[0])
    {
        wall_dir=dir_facing;
        setwall(dir_faing,dir_wall);
    }
    if(next_array[0])
    {
        wall_dir=dir_facing+1;
        setwall(dir_faing,dir_wall);
    }
}

void main()
{
    int m[8][8]={0};
    int curr_x;int curr_y;
    int dir_facing,int dir_wall;
    bool next_arr[3];
    int L_wall;int R_wall;int F_wall;

    while(1)
    {
        if(curr_x==goal && curr_y=goal)
        {
            break;
        }

        IR();

        if(dir_facing==0)
        {
            L_wall=m[curr_x][curr_y-1];
            F_wall=m[curr_x-1][curr_y];
            R_wall=m[curr_x][curr_y+1];
        }
        if(dir_facing==1)
        {

        }
        if(dir_facing==2)
        {

        }
        if(dir_facing==3)
        {

        }
        if(!L_wall)
        {
            dir_facing--;
            turnleft();
        }
        
        while(F_wall)
        {
            dir_facing++;
            turnright();
        }

        //move forward
        dir_facing=(dir_facing+4)%4;
        if(dir_facing==0)
        curr_x--;
        if(dir_facing==1)
        curr_y++;
        if(dir_facing==2)
        curr_x++;
        if(dir_facing==3)
        curr_y--;

        moveforward();



    }
}
