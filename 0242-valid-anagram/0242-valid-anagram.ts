function charInfo(s: string): Map<string, number> {
    const info = new Map<string, number>();
    
    for (let i = 0; i < s.length; i++) {
        if (info.get(s[i]) === undefined)
            info.set(s[i], 1);
        else
            info.set(s[i], info.get(s[i]) + 1);
    }
    return info;
}

function isAnagram(s: string, t: string): boolean {
    if (s.length !== t.length)
        return false;
    const sInfo = charInfo(s);
    const tInfo = charInfo(t);
    
    for (const [c, count] of sInfo) {
        if (tInfo.get(c) !== count)
            return false;
    }
    return true;
};