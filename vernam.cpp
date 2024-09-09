#include <bits/stdc++.h>

using namespace std;

string encrypt(string text, string key, unordered_map<char,int> mp) {
    string result = "";
    for (int i = 0; i < text.size(); i++) {
        int x = mp[text[i]] ^ mp[key[i]];
        if(x>25) x-=26;
        result += (x + 'A');
    }
    return result;
}

string decrypt(string text, string key, unordered_map<char,int> mp) {
    string result = "";
    for (int i = 0; i < text.size(); i++) {
        int x = mp[text[i]] ^ mp[key[i]];
        if(x>25) x-=26;
        result += (x + 'A');
    }
    return result;
}

int main(){

    unordered_map<char,int> mp;
    for(int i=0;i<26;i++){
        mp['A'+i] = i;
    }

    string plain_text;
    cout << "Enter the plain text: ";
    cin >> plain_text;

    string key;
    cout << "Enter the key: ";
    cin >> key;

    string encrypted_text = encrypt(plain_text, key, mp);
    cout << "Encrypted text: " << encrypted_text << endl;

    string decrypted_text = decrypt(encrypted_text, key, mp);
    cout << "Decrypted text: " << decrypted_text << endl;

    return 0;
}