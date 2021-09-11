public static String caesarCipher(String s, int k) {
        StringBuilder sb = new StringBuilder();
        k %= 26;
        for(char c : s.toCharArray()) {
            if((c >= 'a' && c <= 'z')) {
                c += k;
                if(c > 'z') c -= 26;
            }
            else if((c >= 'A' && c <= 'Z')) {
                c += k;
                if(c > 'Z') c -= 26;
            }
            sb.append(c);
        }
        return sb.toString();
    }