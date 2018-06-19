
Solution::Solution()
{
}


Solution::~Solution()
{
}

void PileCake(vector<int>& CakePile, int end)
{
    if (end <= 0)
        return;
    MaxCake maxCake = { 0, CakePile[0] };
    for (int i = 1; i <= end; i++)
        if (maxCake.max < CakePile[i]) {
            maxCake.max = CakePile[i];
            maxCake.index = i;
        }
    if (maxCake.index != 0)
        reverse(CakePile.begin(), CakePile.begin()+ maxCake.index+1);
    reverse(CakePile.begin(), CakePile.begin() + end + 1);
    PileCake(CakePile, end - 1);

}

void Solution::SortTheCake(vector<int>& CakePile) 
{
    PileCake(CakePile, CakePile.size() - 1);
}
