        for (int t = 0; t <= maxTime; t++)
        {
            if (t < (int)a[0].size())
                dp[1][t] = (t == 0 ? a[0][0] : dp[1][t - 1] + a[0][t]);
            else
                dp[1][t] = dp[1][t - 1]; // nếu vượt quá số bài thì giữ nguyên
        }