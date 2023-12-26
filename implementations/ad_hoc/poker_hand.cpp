class Card {
public:
    int value;
    char suit; // Clubs, Diamonds, Hearts, Spades.
    Card(int _value, char _suit) : value(_value), suit(_suit) {}
    bool operator<(const Card& other) const {
        return value < other.value;
    }
};
class Hand {
public:
    vector<Card> cards;
    bool cin_hand() {
        char value; char suit;
        cards.clear();
        for(int i = 0; i < 5; ++i) {
            if (!(cin >> value >> suit)) return false;
            if (value == 'T') value = 10;
            else if (value == 'J') value = 11;
            else if (value == 'Q') value = 12;
            else if (value == 'K') value = 13;
            else if (value == 'A') value = 14;
            else value -= '0';
            cards.pb(Card(value, suit));
        }
        return true;
    }
    void cout_hand() {
        sort(cards.begin(), cards.end());
        for(auto const& card : cards) {
            if (card.value == 10) cout << "T";
            else if (card.value == 11) cout << "J";
            else if (card.value == 12) cout << "Q";
            else if (card.value == 13) cout << "K";
            else if (card.value == 14) cout << "A";
            else cout << card.value;
            cout << card.suit << " ";
        }
        cout << "\n";
    }
    bool is_smallest_straight() const { // Case low A: A 2 3 4 5.
        if (cards[0].value == 2 && cards[1].value == 3 && cards[2].value == 4
            && cards[3].value == 5 && cards[4].value == 14) {
            return true;
        }
        return false;
    }
    int get_order() {
        sort(cards.begin(), cards.end());
        bool same_color = true;
        bool is_straight = true;
        for (int i = 1; i < 5; ++i) {
            if (cards[i].suit != cards[i - 1].suit) {
                same_color = false;
                break;
            }
        }
        for (int i = 1; i < 5; ++i) {
            if (cards[i].value != cards[i - 1].value + 1) {
                is_straight = false;
                break;
            }
        }
        if (is_smallest_straight()) is_straight = true;
        if (same_color && is_straight) return 8; // Straight flush.
        if (cards[0].value == cards[3].value || cards[1].value == cards[4].value) return 7; // Four of a kind.
        if ((cards[0].value == cards[2].value && cards[3].value == cards[4].value)
            || (cards[0].value == cards[1].value && cards[2].value == cards[4].value)) return 6; // Full house.
        if (same_color) return 5; // Flush.
        if (is_straight) return 4; // Straight.
        if (cards[0].value == cards[2].value || cards[1].value == cards[3].value
            || cards[2].value == cards[4].value) return 3; // Three of a kind.
        if ((cards[0].value == cards[1].value && cards[2].value == cards[3].value) ||
            (cards[0].value == cards[1].value && cards[3].value == cards[4].value) ||
            (cards[1].value == cards[2].value && cards[3].value == cards[4].value)) return 2; // Two pairs.
        if (cards[0].value == cards[1].value || cards[1].value == cards[2].value ||
            cards[2].value == cards[3].value || cards[3].value == cards[4].value) return 1; // One pair.
        return 0; // High card.
    }
    bool compare_high_card(const Hand& other) const {
        for (int i = 4; i >= 0; --i) {
            if (cards[i].value != other.cards[i].value) {
                return cards[i].value < other.cards[i].value;
            }
        }
        return false;
    }
    bool operator<(Hand& other) {
        int order1 = get_order(), order2 = other.get_order();
        if (order1 != order2) return order1 < order2;
        int value1 = 0, value2 = 0;
        if (order1 == 1 || order1 == 3 || order1 == 7) { // One pair or Three of a kind or Four of a kind.
            for (int i = 4; i >= 1; --i) {
                if (cards[i].value == cards[i - 1].value) {
                    value1 = cards[i].value;
                    break;
                }
            }
            for (int i = 4; i >= 1; --i) {
                if (other.cards[i].value == other.cards[i - 1].value) {
                    value2 = other.cards[i].value;
                    break;
                }
            }
            if (value1 != value2) return value1 < value2;
        }
        if (order1 == 2) { // Two pairs.
            for (int i = 4; i >= 1; --i) {
                if (cards[i].value == cards[i - 1].value) {
                    value1 = cards[i].value;
                    break;
                }
            }
            for (int i = 4; i >= 1; --i) {
                if (other.cards[i].value == other.cards[i - 1].value) {
                    value2 = other.cards[i].value;
                    break;
                }
            }
            if (value1 != value2) return value1 < value2;
            for (int i = 1; i < 5; ++i) {
                if (cards[i].value == cards[i - 1].value) {
                    value1 = cards[i].value;
                    break;
                }
            }
            for (int i = 1; i < 5; ++i) {
                if (other.cards[i].value == other.cards[i - 1].value) {
                    value2 = other.cards[i].value;
                    break;
                }
            }
            if (value1 != value2) return value1 < value2;
        }
        if (order1 == 4 || order1 == 8) { // Straight or Straight flush.
            if (is_smallest_straight() && !other.is_smallest_straight()) return true;
            if (other.is_smallest_straight()) return false;
        }
        if (order1 == 6) { // Full house.
            for (int i = 4; i >= 2; --i) {
                if (cards[i].value == cards[i - 1].value && cards[i].value == cards[i - 2].value) {
                    value1 = cards[i].value;
                    break;
                }
            }
            for (int i = 4; i >= 2; --i) {
                if (other.cards[i].value == other.cards[i - 1].value && other.cards[i].value == other.cards[i - 2].value) {
                    value2 = other.cards[i].value;
                    break;
                }
            }
            if (value1 != value2) return value1 < value2;
        }
        return compare_high_card(other);
    }
};

