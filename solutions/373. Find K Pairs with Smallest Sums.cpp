        return ans;
    q.push({a[0] + b[0], 0, 0});
    m[to_string(a[0] + b[0]) + "#0"  + "#0"] = 1;
   // int c=1;
    while (q.size()>0&&k >0)
    {
       
         
        auto p = q.top();
        q.pop();
        ans.push_back({a[p.i],b[p.j]});
        if (p.i <= ((int)a.size())-2 && m[to_string(a[p.i + 1] + b[p.j]) + "#" + to_string(p.i + 1) + "#" + to_string(p.j)] == 0)
        {
            q.push({a[p.i + 1] + b[p.j], p.i + 1, p.j});
            m[to_string(a[p.i + 1] + b[p.j]) + "#" + to_string(p.i + 1) + "#" + to_string(p.j)] = 1;
        }
        
       // cout<< (( b.size())-2);
        if ((p.j <=((int)b.size())-2) && m[to_string(a[p.i] + b[p.j + 1]) + "#" + to_string(p.i) + "#" + to_string(p.j + 1)] == 0)
        {
            q.push({a[p.i] + b[p.j + 1], p.i, p.j + 1});
            m[to_string(a[p.i] + b[p.j + 1]) + "#" + to_string(p.i) + "#" + to_string(p.j + 1)] = 1;
        }
        
        
        k--;
    }
        return ans;
    }
};
