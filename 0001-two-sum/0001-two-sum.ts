function twoSum(nums: number[], target: number): number[] {
    // nuberMapこれはハッシュマップで[nums, index]を格納するもの
    const numberMap = new Map<number, number>();
    
    // このロジックは相方がいたら終わるのでnumsのlength分だけループする
    for (let i = 0; i < nums.length; i++) {
        // targetが９の場合 : difference = 9 - 2の値を入れて相方を確保
        const difference = target - nums[i]
        // 基本的に最初はスカスはず！
        // getでpairになるindexを取得はifでundefinedにならないことを確認するため
        const pair = numberMap.get(difference)
        if (pair !== undefined) {
        // return ([index-1, index-2])配列をその場で作って返せる
        // getでdifferenceに対応するindexをとってくる、iの対になるものをdifferenceで持ってるのでiは固定でおk
            return ([pair, i])
        }
        // ifに入らなければ、mapにnumberとindexを登録する hasの引き方はnumber→indexとなる
        // 次にnumberMap.hasで見るときの対象になる
        numberMap.set(nums[i], i)
    }
    // 問題的には解がないことはないとなっているが、明示的にする
    return []
};