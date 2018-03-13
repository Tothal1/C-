
#include <iostream>
#include <vector>

class PrepaidCard {
    public:
        PrepaidCard(std::string name, double balance):       // using variables before function opener,
            name(name), balance(balance) {                   // confusing: person(name), money(balance) might be better
            if (balance < 0) {                               // The card is not available because it has negative money
                throw std::runtime_error("invalid card");
            }
        }

        void purchase(double amount) {                       // Function made inside class!
            if (balance < amount) {                          // So balance and amount do not have to be accessed
                throw std::runtime_error("invalid purchase");
            }

            balance -= amount;
        }

        void charge(double amount){                          // Obvious
            balance += amount;
        }

        std::string get_name() const { return name; }        // Constant name because it never returns anything else than the name
        double get_balance() const { return balance; }       // Constant balance because it never returns anything else than the balance

    private:
        std::string name;
        double balance;
};

class PrepaidCardRow {
    public:
        void update(PrepaidCard card) {                     // Update function that makes a class object card
            for (PrepaidCard& other : cards) {              // Same as: for(int i = 0; i<cards.size(); i++);
                                                            //
                if (other.get_name() == card.get_name()) {
                    other.charge(card.get_balance());
                    return;
                }
            }

            cards.push_back(card);
        }

        PrepaidCard& get(std::string name) {
            for (PrepaidCard& card : cards) {
                if (card.get_name() == name) {
                    return card;
                }
            }

            throw std::runtime_error("card does not exist");
        }

        int size() const { return cards.size(); }

        const PrepaidCard& operator[] (int index) const{
            return cards[index];
        }

    private:
        std::vector<PrepaidCard>cards;
};

const char UPDATE = 'u';
const char PURCHASE = 'p';

int main() {
    PrepaidCardRow row;

    while (true) {
        char type;
        std::cin >> type;

        if (std::cin.eof()) {
            break;
        }

        std::string name;
        std::cin >> name;

        double money;
        std::cin >> money;

        try {
            if (type == UPDATE) {
                row.update(PrepaidCard(name, money));
            } else if (type == PURCHASE) {
             row.get(name).purchase(money);
            }
        } catch (std::runtime_error& e) {
            std::cerr << "error: " << e.what() << std::endl;
        }
    }
    for (int i=0; i<row.size(); i++){
        std::cout  << row[i].get_name() << " has " << row[i].get_balance() << " euros left" << std::endl;
    }
    return 0;
}
