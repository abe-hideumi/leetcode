function twoSum(nums: number[], target: number): number[] {
    // nuberMapこれはハッシュマップで[nums, index]を格納するもの
    const numberMap = new Map<number, number>();
    
    // このロジックは相方がいたら終わるのでnumsのlength分だけループする
    for (let i = 0; i < nums.length; i++) {
        const difference = target - nums[i]
        if (numberMap.has(difference)) {
            return ([numberMap.get(difference), i])
        }
        numberMap.set(nums[i], i)
    }
};