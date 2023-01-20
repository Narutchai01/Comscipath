   for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int temp = map[i][j];
                map[i][j] = map[j][n - i - 1];
                map[j][n - i - 1] = map[n - i - 1][n - j - 1];
                map[n - i - 1][n - j - 1] = map[n - j - 1][i];
                map[n - j - 1][i] = temp;
            }
        }
        สร้าง metrix ขนาด 10*10
