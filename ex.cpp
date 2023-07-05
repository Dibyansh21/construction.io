long long noOfPairs(vector<string>& box) { 
    int n = box.size(); 
    long long ans = 0; 
 
    vector<pair<string, int>> v; 
    for (int i = 0; i < n; i++) { 
        v.push_back({box[i], i}); 
    } 
 
    sort(v.begin(), v.end()); 
 
    for (int i = 0; i < n - 1; i++) { 
        vector<int> charCount(26, 0); 
 
        for (char c : v[i].first) { 
            charCount[c - 'a']++; 
        } 
 
        for (int j = i + 1; j < n; j++) { 
            bool b = true; 
            int odd = 0; 
 
            for (char c : v[j].first) { 
                charCount[c - 'a']++; 
            } 
 
            for (int k = 0; k < 26; k++) { 
                if (charCount[k] % 2 != 0) { 
                    odd++; 
                    if (odd > 1) { 
                        b = false; 
                        break; 
                    } 
                } 
            } 
 
            if (b) 
                ans++; 
 
            for (char x : v[j].first) { 
                charCount[x - 'a']--; 
            } 
        } 
    } 
 
    return ans; 
} 