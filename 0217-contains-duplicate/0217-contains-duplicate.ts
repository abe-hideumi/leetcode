function containsDuplicate(nums: number[]): boolean {
    const numberMap = new Map<number, number>()

    for (let i = 0; i < nums.length; i++) {
        const number = numberMap.get(nums[i])
        if (number !== undefined)
            return true
        numberMap.set(nums[i], i)
    }           
    return false
}