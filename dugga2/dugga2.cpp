
//Name: Oliver Lundin
//liu id: olilu316

#include <iostream>
#include <vector>


int main() {

    //declare variables and vectors

    int one_more;
    int input = 0;
    int win = 0;
    std::vector<int> seq;
    std::vector<int> store;
    int counter = 0;

    //loop menu and store input in a vector

    do
    {
        std::cout << "Enter your ticket numbers: ";

        for (int i = 0; i < 10; i++)
        {
            std::cin >> input;

            seq.push_back(input);

        }

        counter++;

        std::cout << "One more ticket? ";

        std::cin >> one_more;

    } while (one_more == 1);

    //Loop the vector to see if there are any lucky numbers then store them in a vector

    for (int s = 0; s < counter; s++)
    {
        int startnr = s * 10;
        int slutnr = 9 + (s * 10);

        int sum = seq[startnr] + seq[slutnr];

        for (int j = 1; j < 9; j++)
        {
            //create a temp int to avoid overflow

            int temp = startnr + j;
            if (seq[temp] == sum)
            {
                store.push_back(sum);
                win = win + 2000;

            }
        }
    }

    //sort and loop the vector to see if it contains all numbers 1-99
    if (counter > 9)
    {
        //sorting algorithm from lecture 
        for (int& sort1 : seq)
        {
            for (int& sort2 : seq)
            {
                if (sort2 > sort1)
                {
                    // swap
                    int swap = sort1;
                    sort1 = sort2;
                    sort2 = swap;
                }
            }
        }

        //count and compare the vector to a integer
        int search = 1;

        for (int e : seq)
        {

            if (e == search)
            {
                search++;
            }

        }

        if (search > 99)
        {
            win = win + 1000;
        }
    }

    //display possible winnings

    std::cout << "Winning amount: " << win << "\n";

    if (store.size() > 0)
    {
        std::cout << "Your lucky numbers: ";
    }
    for (int display : store)
    {
        std::cout << display << " ";
    }


}


