//MO's algorithm, similar than sqrt decomposition. First sort the queries and then keep adding and
//removing elements until your current interval is the query interval and report the answer
//Usefull when you can compose the answer with a smaller or bigger interval. O((Q+N)sqrt(N))
const int BLOCK = //3; //sqrt(max v.size)

struct Query{
    int l, r, id;
};

//Sort first by block, second by R
bool Query_cmp(Query a, Query b) {
    if(a.l / BLOCK != b.l / BLOCK) {
        return a.l / BLOCK < b.l / BLOCK;
    }
    return a.r < b.r;
}

const int MAX = 1e5+4;
vi v, frec(MAX, 0);
int answer = 0;

//add data to the answer
void add(int i) {
    ++frec[v[i]];
    if(frec[v[i]] == 1) ++answer;
}

//remove data to the answer
void remove(int i) {
    --frec[v[i]];
    if(frec[v[i]] == 0) --answer;
}

void MO() {
    int i, currL = 0, currR = 0;
    v = {2, 3, 1, 1, 2, 1, 2, 3};
    vector<Query> vq = {{0, 5, 0}, {6, 7, 1}, {0, 3, 2}};
    //Sort the queries
    sort(vq.begin(), vq.end(), Query_cmp);

    //The answer contains data of the interval [L..R)
    for(i = 0; i < (int)vq.size(); i++) {
        while(currL < vq[i].l) {
            remove(currL);
            ++currL;
        }
        while(currL > vq[i].l) {
            --currL;
            add(currL);
        }

        while(currR <= vq[i].r) {
            add(currR);
            currR++;
        }
        while(currR -1 > vq[i].r) {
            currR--;
            remove(currR);
        }

        cout << "[" << vq[i].l << " " << vq[i].r << "]:" << answer << endl;
        //ans[vq[i].id] = answer //to sort the answer
    }
}
