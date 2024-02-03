
class Pawn
{
        public:
        char color;
        bool protect;
        bool block;
        bool firstRow;
}
int main(int argc, char * argv[])
{
        
}

/*
        The squares don't need to be contained within the pieces
        if board[i + rollResult].color == piece.color
                invalid move
        
        ##AFTER MOVE##
        #BLOCK#
        if board[i + 1] == board[i].color && board[i + 2].color == board[i].color 
                board[i].block == true && board[i + 1].block == true && board[i + 2].block == true
        if board[i - 1] == board[i].color && board[i - 2].color == board[i].color 
                board[i].block == true && board[i - 1].block == true && board[i - 2].block == true
        if board[i + 1] == board[i].color && board[i - 1].color == board[i].color 
                board[i].block == true && board[i + 1].block == true && board[i - 1].block == true
        else 
                board[i].block == false

        #problem: if we subsequently move this piece, then the other two pieces will still have block / protext
        #cause: this is only if block/protect checking is tied to the moves of individual pieces
        # solution: make block/protect check a function that iterates through the whole board checking each pieces
        and setting their block/protect condition every turn 

        #PROTECT#
        if board[i + 1].color == board[i].color 
                board[i].protect = true;
                board[i + 1].protect = true;

        if board[i - 1].color == board[i].color 
                board[i].protect = true;
                board[i - 1].protect = true;
                
#MOVE BOUNDING#
        if board.size()

*/
