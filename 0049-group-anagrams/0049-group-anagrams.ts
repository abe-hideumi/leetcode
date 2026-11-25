function groupAnagrams(strs: string[]): string[][] {
    const groups = new Map<string, string[]>();

    // 空配列なら空配列を返す
    if (strs.length === 0)
        return [];

    for (const s of strs) {
        // 文字をソートした文字列をキーにする。アナグラム同士は同じキーになる
        // "eat".split("") → ["e","a","t"].sort() → ["a","e","t"].join("") → "aet"
        const key: string = s.split("").sort().join("");

        // get の結果を変数に入れて if で確認すると、string[]かundefinedになるので ? が不要になる
        const group = groups.get(key);
        if (group)
            // 登録済みのキー → 既存のグループの末尾に元の文字列を追加
            group.push(s);
        else
            // 初めてのキー → 元の文字列1つだけの配列を作って登録
            groups.set(key, [s]);
    }

    // Map の valueだけを取り出して配列にする
    // 例: [["eat","tea","ate"], ["tan","nat"], ["bat"]] → string[][] になる
    return Array.from(groups.values());
};