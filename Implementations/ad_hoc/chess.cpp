// Assumptions:
// If two pieces can move to the same cell, then we will not print Tbd3, but Td3 only.
// There are no pawns.
// Can not castle.
// Inspired in the problem the whites move one and do check mate.

string solution;

using Cell = pair<int, int>; // (a, 7).
using Piece = pair<pair<char, int>, Cell>; // ((piece letter, color), position)).

constexpr int COLOR_BLACK = 0;
constexpr int COLOR_WHITE = 1;
constexpr int COLOR_EMPTY = 2;

constexpr int KING = 0;
constexpr int KNIGHT = 1;
constexpr int ROOK = 2;
constexpr int BISHOP = 3;
constexpr int QUEEN = 4;

// map<char, int> symbol2int = { { 'K', KING }, { 'N', KNIGHT }, { 'R', ROOK }, { 'B', BISHOP }, { 'Q', QUEEN } }; // English.
// char int2symbol[5] = { 'K', 'N', 'R', 'BA', 'Q' }; // English.
map<char, int> symbol2int = { { 'R', KING }, { 'C', KNIGHT }, { 'T', ROOK }, { 'A', BISHOP }, { 'D', QUEEN } }; // Spanish.
constexpr char int2symbol[5] = { 'R', 'C', 'T', 'A', 'D' }; // Spanish.

// Possible moves of the pieces of each type.
vector<vector<Cell>> const possible_moves = {
{ {-1, -1}, {-1,  0}, {-1,  1}, { 0, -1}, { 0,  1}, { 1, -1}, { 1,  0}, { 1,  1} }, // King.
{ {-2, -1}, {-2,  1}, {-1, -2}, {-1,  2}, { 1, -2}, { 1,  2}, { 2, -1}, { 2,  1} }, // Knight.
{ {-1,  0}, { 0, -1}, { 0,  1}, { 1,  0} }, // Rook.
{ {-1, -1}, {-1,  1}, { 1, -1}, { 1,  1} }, // Bishop.
{ {-1, -1}, {-1,  0}, {-1,  1}, { 0, -1}, { 0,  1}, { 1, -1}, { 1,  0}, { 1,  1} } // Queen.
};

constexpr Piece empty_piece = { { ' ', COLOR_EMPTY }, {-1, -1} };
// The board will keep track of all the pieces.
vector<vector<Piece>> board(8, vector<Piece>(8, empty_piece));
// Keeps all the moves done. If moves[i].se != empty_piece, then the piece was captured.
vector<pair<pair<Piece, Piece>, Piece>> moves;

void reset() {
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) board[i][j] = empty_piece;
    moves.clear();
}
void insert_piece(string const& s, int color) { // Example format "Td3".
    Piece const piece = { { s[0], color }, { s[1] - 'a', s[2] - '1' } };
    board[piece.second.first][piece.second.second] = piece;
}
// Return true if the position is inside the board.
bool exists(Cell const& a) {
    if(a.first < 0 || a.first > 7 || a.second < 0 || a.second > 7) return false;
    return true;
}
int get_color(Cell const& a) {
    return board[a.first][a.second].first.second;
}
int get_symbol_int(Piece const& piece) {
    return symbol2int[piece.first.first];
}
int get_color(Piece const& piece) {
    return piece.first.second;
}
int get_x(Piece const& piece) {
    return piece.second.first;
}
int get_y(Piece const& piece) {
    return piece.second.second;
}
void debug(Piece const& p) {
    cout << "(" << p.fi.fi << " " << p.fi.se << " " << p.se.fi << " " << p.se.se << ")" << endl;
}
void debug() { // Debug the non empty Pieces.
    cout << "[";
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(get_color({i, j}) == COLOR_EMPTY) continue;
            else debug(board[i][j]);
        }
    }
    cout << "]" << endl;
}
// Move the piece_before to the new cell.
void do_move(Piece piece_before, Cell cell) {
    Piece piece_after = { piece_before.first, cell };
    moves.pb({ { piece_before, piece_after }, board[cell.first][cell.second] });
    board[get_x(piece_before)][get_y(piece_before)] = empty_piece;
    board[get_x(piece_after)][get_y(piece_after)] = piece_after;
}
void undo_move() {
    auto const last_move = moves.back(); moves.pop_back();
    board[get_x(last_move.fi.fi)][get_y(last_move.fi.fi)] = last_move.fi.fi;
    board[get_x(last_move.fi.se)][get_y(last_move.fi.se)] = last_move.se;
}

// Return true if the color is doing a check to the other color.
bool is_check(int const color) {
    for(auto& el : board) for(auto& piece : el) {
        if(get_color(piece) != color) continue;
        for(auto& dx : possible_moves[get_symbol_int(piece)]) {
            for(int k = 1; k <= 7; k++) {
                if(k > 1) {
                    if(get_symbol_int(piece) == KNIGHT) break;
                    if(get_symbol_int(piece) == KING) break;
                }
                Cell new_position = { get_x(piece) + k * dx.first, get_y(piece) + k * dx.second };
                if(!exists(new_position)) break;
                if(get_color(new_position) == color) break;
                if(board[new_position.first][new_position.second].first == mp(int2symbol[KING], color ^ 1)) return true;
                if(get_color(new_position) == (color ^ 1)) break;
            }
        }
    }
    return false;
}

// Return true if color is doing a check mate to the other color.
bool is_check_mate(int const color) {
    bool ret;
    if(!is_check(color)) return false;
    for(auto& el : board) for(auto& piece : el) {
        if(get_color(piece) != (color ^ 1)) continue;
        if(get_symbol_int(piece) != KING) continue;
        for(auto& dx : possible_moves[get_symbol_int(piece)]) {
            Cell new_position = { get_x(piece) + dx.first, get_y(piece) + dx.second };
            if(!exists(new_position)) continue;
            if(get_color(new_position) == (color ^ 1)) continue;
            do_move(piece, new_position);
            ret = is_check(color);
            undo_move();
            if(!ret) return false;
        }
    }
    return true;
}

// The color moves one piece.
void generate_next_move(int const color) {
    bool ok = false;
    for(auto& el : board) for(auto& piece : el) {
        if(get_color(piece) != color) continue;
        for(auto& dx : possible_moves[get_symbol_int(piece)]) {
            for(int k = 1; k <= 7; k++) {
                if(k > 1) {
                    if(get_symbol_int(piece) == KNIGHT) break;
                    if(get_symbol_int(piece) == KING) break;
                }
                Cell new_position = { get_x(piece) + k * dx.first, get_y(piece) + k * dx.second };
                if(!exists(new_position)) break;
                if(get_color(new_position) == color) break;
                do_move(piece, new_position);
                if(is_check(color ^ 1)) {
                    undo_move(); // The king will be in check.
                    continue;
                }
                if(is_check_mate(color)) {
                    ok = true;
                }
                undo_move();
                if(ok) {
                    if(solution != "NO") {
                        solution = ">1";
                        return;
                    }
                    solution = string(1, piece.first.first) + string(1, new_position.first + 'a') + to_string(new_position.second + 1);
                    ok = false;
                }
                if(get_color(new_position) == (color ^ 1)) break;
            }
        }
    }
}

