function groupAnagrams(strs: string[]): string[][] {
    const strsMap = new Map <string, string[]>();

    if (strs.length === 0)
        return  [];
    else if (strs.length === 1) 
        return [[strs[0]]];
    for (let i = (strs.length - 1); i >= 0; --i) {
        let tmp : string = strs[i].split("").sort().join("");
        if (strsMap.has(tmp)) {
            strsMap.get(tmp)?.push(strs[i]);
        }
        else
            strsMap.set(tmp, [strs[i]]);
    }
    return Array.from(strsMap.values());
};