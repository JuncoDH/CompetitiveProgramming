//Funciona pero pasar a una clase

const int MAX = ;
vi parent(MAX), Rank(MAX);
void ini(){
	int i;
	for(i=0; i < n; ++i)parent[i]=i;
	for(i=0; i < n; ++i)Rank[i]=0;
}

int find_parent(int a){
	if(parent[a] == a)return a;
	return parent[a] = find_parent(parent[a]);
}

bool connected(int a, int b){
	if(find_parent(a) == find_parent(b))return true;
	
	return false;
}

void Union(int a, int b){
	int x, y;
	x=find_parent(a);
	y=find_parent(b);
	
	if(x == y)return;
	
	if(Rank[x] > Rank[y]){
		parent[y] = x;
	}
	else if(Rank[x] < Rank[y]){
		parent[x] = y;
	}
	else{
		parent[x]=parent[y];
		Rank[y]++;
	}
}

