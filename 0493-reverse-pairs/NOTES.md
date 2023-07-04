follow similar algoirthm to [inversion count](https://www.codingninjas.com/studio/problems/count-inversions_615)
but the fundamental difference is near merging, in inversion count, we are just seeing greater than, hence we can break in one loop
but here we need to find nums[i] > 2 * nums[j], so we need to find the right element for which all the left are possible
![image](https://user-images.githubusercontent.com/73538974/250906504-118c24b1-8dc9-437d-a5d6-8330c1b6ec52.png)
in this image, we are finding the correct right posisiton for which it is failing, and the left of right_pointer is satisfied by all the number of the right
we are retaining the count and adding, hence this is optimal
![WhatsApp Image 2023-07-04 at 18 19 25](https://user-images.githubusercontent.com/73538974/250905859-16f3d311-51a2-495c-bfbf-442b3825f387.jpg)
​
​