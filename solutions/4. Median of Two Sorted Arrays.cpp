        if ((m + n) % 2 == 0)
        {
            if (mid2 == 0)
                l = a[mid1 - 1];
            else if (mid1 == 0)
                l = b[mid2 - 1];
            else
                l = max(a[mid1 - 1], b[mid2 - 1]);
            if (mid2 == m)
                r = a[mid1];
            else if (mid1 == n)
                r = b[mid2];
            else
                r = min(a[mid1], b[mid2]);
            return (l * 1.0 + r * 1.0) / 2;
        }
        else
        {
            if (mid2 == 0)
                l = a[mid1 - 1];
            else if (mid1 == 0)
                l = b[mid2 - 1];
            else
                l = max(a[mid1 - 1], b[mid2 - 1]);
            return l * 1.0;
        }
        return 1.0;
    }
};
