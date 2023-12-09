#include <iostream>
#include <vector>
using namespace std;
struct Booking
{
    int booking_id;
    int customer_id;
    char pick_up;
    char drop;
    int amount;
};
class Taxi
{
public:
    int id;
    int earnings;
    char current_point;
    int free_time;
    vector<Booking> b;
    Taxi(int idx)
    {
        id = idx;
        earnings = 0;
        current_point = 'A';
        free_time = 6;
    }
    void printDetail()
    {
        cout << "Taxi ID:" << id + 1 << ", Current Point:" << current_point << ", Total earnings:" << earnings << ", Next free time:" << free_time << endl;
        cout << "Booking ID\tCustomer ID\tPickup Point\t Drop Point\tAmount" << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i].booking_id << "\t\t" << b[i].customer_id << "\t\t" << b[i].pick_up << "\t\t" << b[i].drop << "\t\t" << b[i].amount << endl;
        }
    }
    void assignTaxi(int amount, char pick_up, char drop, int booking_id, int time, int temp)
    {
        Booking obj = {booking_id, booking_id, pick_up, drop, amount};
        earnings += amount;
        current_point = drop;
        free_time = time + temp;
        b.push_back(obj);
        cout << "Taxi " << id + 1 << " is Alloted" << endl;
        cout << "Amount:" << amount << endl;
    }
};
class ReservationSystem
{
public:
    int id;
    vector<Taxi> taxies;
    ReservationSystem(int num)
    {
        for (int i = 0; i < num; i++)
        {
            Taxi obj(i);
            taxies.push_back(obj);
        }
        id = 1;
    }
    void printDetails()
    {
        for (int i = 0; i < taxies.size(); i++)
        {
            taxies[i].printDetail();
            cout << endl;
        }
    }

    int nearestTaxi(char pick_up, int time)
    {
        int nearest = -1;
        char temp;
        int min_distance = INT_MAX;
        int taxiIDWithLowestEarning;
        int lowest_earning = INT_MAX;
        for (int i = 0; i < taxies.size(); i++)
        {
            if (taxies[i].free_time <= time)
            {
                if (taxies[i].current_point == pick_up)
                {
                    temp = taxies[i].current_point;
                    nearest = i;
                    min_distance = 0;
                    break;
                }
                else
                {
                    int diff = (int)pick_up - taxies[i].current_point;
                    if (min_distance > diff)
                    {
                        min_distance = diff;
                        nearest = i;
                    }
                }
            }
        }
        if (nearest == -1)
            return -1;

        // Finding Taxi with lowest earning if one or more taxi is available with minimum distance
        for (int i = 0; i < taxies.size(); i++)
        {
            int diff = (int)pick_up - taxies[i].current_point;
            if (min_distance == diff)
            {
                if (taxies[i].earnings < lowest_earning)
                {
                    lowest_earning = taxies[i].earnings;
                    taxiIDWithLowestEarning = i;
                }
            }
        }
        return taxiIDWithLowestEarning;
    }

    void bookTaxi()
    {
        char pick_up, drop;
        int time;
        cout << "Pick up:";
        cin >> pick_up;
        cout << "Drop:";
        cin >> drop;
        cout << "Pick up time:";
        cin >> time;
        if (!((pick_up >= 'A' && pick_up <= 'E') && (drop >= 'A' && drop <= 'E')))
        { // Change the range of points/stop here
            cout << "Invalid pickup or drop point (Choose Between A to E)" << endl;
            return;
        }
        int index = nearestTaxi(pick_up, time);
        if (index == -1)
        {
            cout << "Booking rejected!" << endl;
            return;
        }
        // Calculate Fare
        int temp = abs(pick_up - drop);
        int distance = temp * 15;
        int total_fare = 100 + ((distance - 5) * 10);
        // Assigning Taxi
        taxies[index].assignTaxi(total_fare, pick_up, drop, id++, time, temp);
    }
};
int main()
{
    ReservationSystem r(4);
    int choice;
    do
    {
        cout << "1 -> Book\n2 -> Print Details\n3 -> Exit\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            r.bookTaxi();
            break;
        case 2:
            r.printDetails();
            break;
        default:
            break;
        }
    } while (choice != 3);
}