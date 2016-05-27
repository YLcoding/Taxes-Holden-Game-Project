#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int rand_0toN1(int n);
void draw_a_card();
int select_next_available(int n);
int maxbit(int [],int);
void radixsort(int [],int);
void Texas_Holdem_Draw();
void Text_and_Input();
int Royal_Stringt_Flush(int [],char [],int);
int Straight_Flush(int [],char [],int);
int Four_of_a_Kind(int [],int);
int Full_House(int [],int);
int Flush(char [],int);
int Straight(int [],int);
int Three_of_a_Kind(int [],int);
int Two_Pair(int [],int);
int One_Pair(int [],int);
int Compare(int [],char [],int);
void instruction();
int play1_chip;
int play2_chip;
int play1_bet;
int play2_bet;
int pot;
string name;
int current_max;
bool card_drawn[52];
int cards_remaining = 52;
char suits[4] = {3,4,5,6};
int ranks[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
void Print_Card(int [],char []);
int Cards_Need_to_Be_Drawn;
int r;
char s;
string what_to_do;
int desk_ranks[5];
char desk_suits[5];
int bot_hand_ranks[2];
char bot_hand_suits[2];
int hand_ranks[2];
char hand_suits[2];
int hand_and_desk_ranks[7];
char hand_and_desk_suits[7];
int p_winning_hand[5];
int b_winning_hand[5];
int royal_control;
int straight_flush_control;
char flush_control;

void Print_Card(int ranks[],char suit[]){
    //string ranks_1=std::to_string(1);
    string top,middle_1,middle_2,middle_3,bottom;
    char top_left=218;
    char top_bottom_middle=196;
    char top_right=191;
    char middle_head_tail=179;
    char bottom_left=192;
    char bottom_right=217;
    char suit_shape=3;
    int Card_Have_Drawn=1;
    top=top_left;
    top.append<char>(7,top_bottom_middle);
    top.append<char>(1,top_right);
    middle_1=middle_head_tail;
    bottom=bottom_left;
    bottom.append<char>(7,top_bottom_middle);
    bottom.append<char>(1,bottom_right);
    middle_2=middle_head_tail;
    middle_2.append(7,'\0');
    middle_2.append(1,middle_head_tail);
    for(int Card_top=1;Card_top<=Cards_Need_to_Be_Drawn;Card_top++){
        cout<<top;
    }
    cout<<endl;
    for(int Card_middle_1=0;Card_middle_1<Cards_Need_to_Be_Drawn;Card_middle_1++){
        if(ranks[Card_middle_1]==10){
            cout<<middle_1<<ranks[Card_middle_1]<<"     "<<middle_1;
        }
        if(ranks[Card_middle_1]>10){
            switch(ranks[Card_middle_1]){
                case 11:
                    cout<<middle_1<<" "<<"J"<<"     "<<middle_1;
                    break;
                case 12:
                    cout<<middle_1<<" "<<"Q"<<"     "<<middle_1;
                    break;
                case 13:
                    cout<<middle_1<<" "<<"K"<<"     "<<middle_1;
                    break;
                case 14:
                    cout<<middle_1<<" "<<"A"<<"     "<<middle_1;
                    break;
                //default:
                    //cout<<"WARNING";
            }
        }
        if(ranks[Card_middle_1]<10)
            cout<<middle_1<<" "<<ranks[Card_middle_1]<<"     "<<middle_1;
    }
    cout<<endl;
    for(int Card_middle_2=0;Card_middle_2<Cards_Need_to_Be_Drawn;Card_middle_2++){
        cout<<middle_1<<" "<<suit[Card_middle_2]<<"     "<<middle_1;
    }
    cout<<endl;
    for(int Card_middle_3=0;Card_middle_3<4;Card_middle_3++){
        for(int Card_middle_4=0;Card_middle_4<Cards_Need_to_Be_Drawn;Card_middle_4++){
            cout<<middle_2;
        }
        cout<<endl;
    }
    for(int Card_bottom=0;Card_bottom<Cards_Need_to_Be_Drawn;Card_bottom++){
        cout<<bottom;
    }
}
void draw_a_card() {


int n, card;

n = rand_0toN1(cards_remaining--);

card = select_next_available(n);

r = card % 13+2; // r = random 2 to 14

s = (card / 13)+3; // s = random 3 to 6



}
int select_next_available(int n)
 {
     int i = 0;
    while (card_drawn[i])
        i++;
    while (n-- > 0) {
        i++;
    while (card_drawn[i])
        // Skip past cards
        i++;
    }
    card_drawn[i] = true;
    return i;
}
void re_shuffle(){
    cards_remaining=52;
    for(int i=0;i<52;i++){
        card_drawn[i]=false;
    }
}
int rand_0toN1(int n)
{
      return rand() % n;
}
void Texas_Holdem_Draw(){
    int round=0;
    cout<<"Please enter your name:";
    getline(cin,name);
    cout<<"Enter the number of chips that you wish to begin:";
    cin>>play1_chip;
    play2_chip=play1_chip;
    cout<<"The game has started!"<<endl;
    while(1){
    cout<<"Round "<<++round<<endl;
    cout<<"Pre-flop"<<endl;
    Cards_Need_to_Be_Drawn=2;
    for(int i=0;i<Cards_Need_to_Be_Drawn;i++){
        draw_a_card();
        hand_ranks[i]=r;
        hand_suits[i]=s;
    }
    for(int i=0;i<Cards_Need_to_Be_Drawn;i++){
        draw_a_card();
        bot_hand_ranks[i]=r;
        bot_hand_suits[i]=s;
    }
    Print_Card(hand_ranks,hand_suits);
    cout<<endl;
    instruction();
    if(what_to_do=="folds"){
        continue;
    }
    cin.get();
    cout<<"Flop"<<endl;
    Cards_Need_to_Be_Drawn=3;
    for(int i=0;i<Cards_Need_to_Be_Drawn;i++){
        draw_a_card();
        desk_ranks[i]=r;
        desk_suits[i]=s;
    }
    Print_Card(desk_ranks,desk_suits);
    cout<<endl;
    instruction();
    if(what_to_do=="folds"){
        continue;
    }
    cin.get();
    cout<<"Turn"<<endl;
    Cards_Need_to_Be_Drawn=4;
    for(int i=3;i<Cards_Need_to_Be_Drawn;i++){
        draw_a_card();
        desk_ranks[i]=r;
        desk_suits[i]=s;
    }
    Print_Card(desk_ranks,desk_suits);
    cout<<endl;
    instruction();
    if(what_to_do=="folds"){
        continue;
    }
    cin.get();
    cout<<"River"<<endl;
    Cards_Need_to_Be_Drawn=5;
    for(int i=4;i<Cards_Need_to_Be_Drawn;i++){
        draw_a_card();
        desk_ranks[i]=r;
        desk_suits[i]=s;
    }
    Print_Card(desk_ranks,desk_suits);
    cout<<endl;
    instruction();
    if(what_to_do=="folds"){
        continue;
    }
    cin.get();
    int all_ranks[7];
    char all_suit[7];
    int bot_all_ranks[7];
    char bot_all_suit[7];
    for(int i=0;i<7;i++){
        if(i<=1){
            all_ranks[i]=hand_ranks[i];
            all_suit[i]=hand_suits[i];
        }else{
            all_ranks[i]=desk_ranks[i-2];
            all_suit[i]=desk_suits[i-2];
        }
    }
    for(int i=0;i<7;i++){
        if(i<=1){
            bot_all_ranks[i]=bot_hand_ranks[i];
            bot_all_suit[i]=bot_hand_suits[i];
        }else{
            bot_all_ranks[i]=desk_ranks[i-2];
            bot_all_suit[i]=desk_suits[i-2];
        }
    }
    int player_hand=0;
    int bot_hand=0;
    player_hand=Compare(all_ranks,all_suit,0);
    bot_hand=Compare(bot_all_ranks,bot_all_suit,1);

    if(play2_chip==0){
        cout<<"Congratulation! You just win the game. You beat the sh*t out of the bot. GJ!"<<endl;
        break;
    }else if(play1_chip==0){
        cout<<"WTF! You just lose to a bot? You sucks! Shame on you!"<<endl;
        break;
    }
    re_shuffle();
    }

}

int Royal_Stringt_Flush(int ranks[],char suits[],int n){
    bool royal[5];
    int royal_true=0;
    for(int b=0;b<6;b++){
        royal[b]=false;
    }
    for(int i=0;i<=6;i++){
        if(ranks[i]==14&&suits[i]==6){
            royal[0]=true;
        }
        if(ranks[i]==13&&suits[i]==6){
            royal[1]=true;
        }
        if(ranks[i]==12&&suits[i]==6){
            royal[2]=true;
        }
        if(ranks[i]==11&&suits[i]==6){
            royal[3]=true;
        }
        if(ranks[i]==10&&suits[i]==6){
            royal[4]=true;
        }
    }
    for(int a=0;a<5;a++){
        if(royal[a]==true)
            royal_true++;
    }
    if(royal_true>=5)
        return 9;
    else
        return 0;
}
int Straight_Flush(int ranks[],char suit[],int n){
    char suit_1[7];
    int ranks_1[7];
    for(int i=0;i<7;i++){
        ranks_1[i]=ranks[i];
    }
    radixsort(ranks,7);
    for(int i=0;i<7;i++){
        for(int a=0;a<7;a++){
            if(ranks[i]==ranks_1[a]){
                suit_1[i]=suits[a];
            }
        }
    }
    for(int i=0;i<7;i++){
        suits[i]=suit_1[i];
    }
    bool straight_flush[4];
    int true_straight=0;
    for(int b=0;b<4;b++){
        straight_flush[b]=false;
    }
    for(int i=6;i>3;i--){
            if(ranks[i]-1==ranks[i-1]&&suit_1[i]==suit_1[i-1]){
                straight_flush[0]=true;
                if(n==1){
                    p_winning_hand[i]=ranks[i];
                    p_winning_hand[i-1]=ranks[i-1];
                }else{
                    b_winning_hand[i]=ranks[i];
                    b_winning_hand[i-1]=ranks[i-1];
                }
            }
            if(ranks[i]-2==ranks[i-2]&&suit_1[i]==suit_1[i-2]){
                straight_flush[1]=true;
                if(n==1){
                    p_winning_hand[i-2]=ranks[i-2];
                }else{
                    b_winning_hand[i-2]=ranks[i-2];
                }
            }
            if(ranks[i]-3==ranks[i-3]&&suit_1[i]==suit_1[i-3]){
                straight_flush[2]=true;
                if(n==1){
                    p_winning_hand[i-3]=ranks[i-3];
                }else{
                    b_winning_hand[i-3]=ranks[i-3];
                }
            }
            if(ranks[i]-4==ranks[i-4]&&suit_1[i]==suit_1[i-4]){
                straight_flush[3]=true;
                if(n==1){
                    p_winning_hand[i-4]=ranks[i-4];
                }else{
                    b_winning_hand[i-4]=ranks[i-4];
                }
            }
            if(ranks[i]-4==2&&suit_1[i]==suit_1[6]&&ranks[6]==14){
                straight_flush[3]=true;
            }
            for(int s=0;s<4;s++){
                if(straight_flush[s]==false){
                    true_straight++;
                }
            }
            if(true_straight>0){
                for(int v=0;v<4;v++)
                    straight_flush[v]=false;
                true_straight=0;
            }
    }
    true_straight=0;
    for(int s=0;s<4;s++){
        if(straight_flush[s]==false)
            true_straight++;
    }
    straight_flush_control=ranks[6];
    if(true_straight==0)
        return 8;
    else
        return 0;
}
int Four_of_a_Kind(int ranks[],int n){
    radixsort(ranks,7);
    int rank_four=0;
    int true_four=0;
    for(int i=0;i<5;i++){
        for(int a=0;a<7;a++){
            if(ranks[i]==ranks[a]&&i!=a){
                true_four++;
                rank_four=ranks[i];
              /*  if(n==1){
                    p_winning_hand[i]=ranks[a];
                }else{
                    b_winning_hand[i]=ranks[a];
                } */
            }
            for(int i=6;i>=0;i--){
                if(ranks[i]!=rank_four){
                    if(n==1){
                        p_winning_hand[4]=ranks[i];
                    }else{
                        b_winning_hand[4]=ranks[i];
                    }
                break;
                }
            }
        }
        if(true_four>=3){
             if(n==1){
                 for(int i=0;i<4;i++)
                    p_winning_hand[i]=rank_four;
                }else{
                 for(int i=0;i<4;i++)
                    b_winning_hand[i]=rank_four;
                }
            break;
        }else
            true_four=0;
    }

    if(true_four>=3){
        return 7;
    }else
        return 0;
}
int Full_House(int ranks[],int n){
    int true_three=0;
    int three_number=0;
    int two_number=0;
    for(int i=0;i<5;i++){
        for(int a=0;a<7;a++){
            if(ranks[i]==ranks[a]&&i!=a){
                true_three++;
                three_number=ranks[i];
                if(n==1){
                    p_winning_hand[i]=three_number;
                }else{
                    b_winning_hand[i]=three_number;
                }
            }
        }
        if(true_three>=2){
            break;
        }else{
            true_three=0;
        }
    }
    int e=3;
    if(true_three>=2){
        for(int b=0;b<6;b++){
            for(int c=0;c<7;c++){
                if(ranks[b]==ranks[c]&&ranks[b]!=three_number&&b!=c){
                    two_number++;
                    if(e>1){
                        if(n==1){
                            p_winning_hand[e]=two_number;
                        }else{
                            b_winning_hand[e]=two_number;
                        }
                        e--;
                    }

                }
            }
            if(two_number>=1){
                break;
            }else
                two_number=0;
        }

    }
    if(two_number>=1)
        return 6;
    else
        return 0;
}

int Flush(char suits[],int n){
    int true_flush=0;
    for(int i=0;i<3;i++){
        for(int a=0;a<7;a++){
            if(suits[i]==suits[a]&&i!=a){
                true_flush++;
                flush_control=suits[i];
            }
        }
        if(true_flush>=4){
            return 5;
        }else{
            true_flush=0;
        }
    }
    return 0;
}
int Straight(int ranks[],int n){
    radixsort(ranks,7);
    int straight=4;
    int temp=ranks[6];
    for(int i=5;i>=0;i--){
        if(temp-1==ranks[i]){
            if(n==1){
                p_winning_hand[straight]=temp;
            }else{
                b_winning_hand[straight]=temp;
            }
            straight--;
            temp=ranks[i];
            if(straight==1&&ranks[0]+12==ranks[6]){
                if(n==1){
                    p_winning_hand[straight]=temp;
                }else{
                    b_winning_hand[straight]=temp;
                }
                straight--;
                temp=ranks[6];
            }
            if(straight<=0){
                if(n==1){
                    p_winning_hand[straight]=temp;
                }else{
                    b_winning_hand[straight]=temp;
                }
                return 4;
            }
        }else{
            temp=ranks[i];
            if(n==1){
                p_winning_hand[4]=temp;
            }else{
                b_winning_hand[4]=temp;
            }
            straight=4;
            }
        }
        return 0;
}
int Three_of_a_Kind(int ranks[],int n){
    radixsort(ranks,7);
    int three_number;
    int true_four=0;
    for(int i=0;i<5;i++){
        for(int a=0;a<7;a++){
            if(ranks[i]==ranks[a]&&i!=a){
                true_four++;
                three_number=ranks[i];
                if(n==1){
                    p_winning_hand[i]=three_number;
                }else{
                    b_winning_hand[i]=three_number;
                }
            }
        }
        if(true_four>=2){
            break;
        }else{
            true_four=0;
        }
    }
        for(int i=6;i>2;i--){
            int b=4;
            int Max=ranks[i];
            if(Max>ranks[i-1]&&Max!=three_number){
                if(n==1&&b>=3){
                    p_winning_hand[b]=Max;
                    b--;
                }else if(n==2&&b>=3){
                    b_winning_hand[b]=Max;
                    b--;
                }
            }
        }
    if(true_four>=2)
        return 3;
    else
        return 0;
}
int Two_Pair(int ranks[],int n){
    radixsort(ranks,7);
    int two_pair=4;
    for(int i=5;i>=0;i--){
        if(ranks[i+1]==ranks[i]){
            if(n==1){
                int a=0;
                while(a<2){
                b_winning_hand[two_pair-a]=ranks[i];
                a++;
                }
            }else{
                int a=0;
                while(a<2){
                p_winning_hand[two_pair-a]=ranks[i];
                a++;
                }
            }
            two_pair-=2;
            if(two_pair<=0){
                break;
            }
        }
    }
    if(two_pair<=0){
        for(int i=6;i>=0;i--){
            if(ranks[i]!=b_winning_hand[2]&&ranks[i]!=b_winning_hand[4]&&ranks[i]!=p_winning_hand[2]&&ranks[i]!=p_winning_hand[4]){
                if(n==1){
                    b_winning_hand[0]=ranks[i];
                    break;
                }else{
                    p_winning_hand[0]=ranks[i];
                    break;
                }
            }
        }
        return 3;
    }else{
        return 0;
    }
}
int One_Pair(int ranks[],int n){
    radixsort(ranks,7);
    bool one_pair;
    for(int i=5;i>=0;i--){
        if(ranks[i+1]==ranks[i]){
            if(n==1){
                int a=0;
                while(a<2){
                b_winning_hand[a]=ranks[i];
                a++;
                }
                one_pair=true;
                int c=4;
                for(int b=6;b>=0;b--){
                    if(ranks[b]!=ranks[i]){
                        b_winning_hand[c]=ranks[b];
                        c--;
                        if(c<=1){
                            break;
                        }
                    }
                }
                break;
            }else{
                int a=0;
                while(a<2){
                p_winning_hand[a]=ranks[i];
                a++;
                }
                one_pair=true;
                int c=4;
                for(int b=6;b>=0;b--){
                    if(ranks[b]!=ranks[i]){
                        p_winning_hand[c]=ranks[b];
                        c--;
                        if(c<=1){
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    if(one_pair){
        return 2;
    }else{
        return 0;
    }
}
int Compare(int ranks[],char suits[],int n){
    if(Royal_Stringt_Flush(ranks,suits,n)){
        cout<<name<<" has Royal Stringt Flush!";
        return 9;
    }
    if(Straight_Flush(ranks,suits,n)){
        cout<<name<<" has Stringt Flush!";
        return 8;
    }
    if(Four_of_a_Kind(ranks,n)){
        cout<<name<<" has Four of a Kind!";
        return 7;
    }
    if(Full_House(ranks,n)){
        cout<<name<<" has Full House!";
        return 6;
    }
    if(Flush(suits,n)){
        cout<<name<<" has Flush!";
        return 5;
    }
    if(Straight(ranks,n)){
        cout<<name<<" has Stringt!";
        return 4;
    }
    if(Three_of_a_Kind(ranks,n)){
        cout<<name<<" has Three of a Kind!";
        return 3;
    }
    if(Two_Pair(ranks,n)){
        cout<<name<<" has Two Pair!";
        return 2;
    }
    if(One_Pair(ranks,n)){
        cout<<name<<" has One Pair!";
        return 1;
    }else
        return 0;
}
void instruction(){
    if(play1_chip<=0){
        cout<<"You have no more chips"<<endl;
    }else{
        while(1){
            cout<<"What would you do?(check/all_in/bet/folds):";
            cin>>what_to_do;
            if(what_to_do=="check"){
                if(play1_bet>=play2_bet){
                    break;
                }else{
                    cout<<"You can't check. Please make a bet or fold"<<endl;
                    continue;
                }
            }
            if(what_to_do=="all_in"){
                current_max=play1_chip;
                pot+=play1_chip;
                play1_chip=0;
                cout<<"YOLO!"<<endl;
                break;
            }
            if(what_to_do=="bet"){
                cout<<"The current bet is "<<current_max<<", please place a higher bet:";
                cin>>play1_bet;
                if(play1_bet>=current_max){
                    current_max=play1_bet;
                    play1_chip-=play1_bet;
                    pot+=play1_bet;
                    break;
                }else{
                    cout<<"The bet is too lower, please place a higher bet"<<endl;
                    continue;
                }
            }
            if(what_to_do=="folds"){
                break;
            }
            cout<<"Wrong entry, Please try again"<<endl;
            continue;

        }
    }
}

int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];		///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        p *= 10;
        ++d;
    }
    return d;
/*    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;*/
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;cc

            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}
int main()
{
    srand(time(0));
    Texas_Holdem_Draw();
}

