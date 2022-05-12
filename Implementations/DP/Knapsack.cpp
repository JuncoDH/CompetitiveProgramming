// You want to maximize your prestige but you only have a budget of <= MAX_KNAP.
vll knapsack(MAX_KNAP + 1, 0);
for(i = 0; i < MAX_N; i++) {
    if(max_prestige[i] == 0) continue;
    for(j = MAX_KNAP; j >= 0; j--) {
        if(j + min_cost[i] < MAX_KNAP+1)
            knapsack[j + min_cost[i]] = max(knapsack[j + min_cost[i]], knapsack[j] + max_prestige[i]);
    }
}

