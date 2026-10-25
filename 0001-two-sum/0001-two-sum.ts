function twoSum(nums: number[], target: number): number[] {
    // nuberMapこれはハッシュマップで[nums, index]を格納するもの
    const numberMap = new Map<number, number>();
    
    // このロジックは相方がいたら終わるのでnumsのlength分だけループする
    for (let i = 0; i < nums.length; i++) {
        // targetが９の場合
        // difference = 9 - 2の値を入れて相方を確保
        const difference = target - nums[i]
        // mapにdifferenceがあればこの条件入る
        // 基本的に最初はスカスはず！
        if (numberMap.has(difference)) {
            // return ([index-1, index-2])配列をその場で作って返せる
            // getでdifferenceに対応するindexをとってくる、iの対になるものをdifferenceで持ってるのでiは固定でおk
            // getでもしiを送ったらそのindexのnumberが帰ってくる認識
            return ([numberMap.get(difference), i])
        }
        // ifに入らなければ、mapにnumberとindexを登録する
        // 次にnumberMap.hasで見るときの対象になる
        numberMap.set(nums[i], i)
    }
};