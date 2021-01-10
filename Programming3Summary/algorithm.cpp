

	//  C++17  or greater


// Algorithms
#include <numeric>	 
#include <algorithm>


// Utility
#include <iostream>
#include <iterator>
#include <random>


	// Type placeholders

	using Type       = int;			        // Change to see what works and what doesn't
	using Result     = int;			        // Change to see what works and what doesn't
	using Container  = std::vector<Type>;   // Change to see what works and what doesn't

	// Functor placeholders

	//Predicate
	auto unary_pred  = [](Type)       -> bool { return bool();   };
	auto binary_pred = [](Type, Type) -> bool { return bool();   };
	auto comp        = binary_pred;

	//Operator
	auto func        = []()           -> auto { return Result(); };
	auto unary_op    = [](Type)       -> auto { return Result(); };
	auto binary_op   = [](Type, Type) -> auto { return Result(); };

	// Container placeholder

	Container container{};

	// Begin/End placeholder

	auto begin       = std::begin(container);
	auto end         = std::end  (container);
	auto begin_1     = begin;
	auto begin_2     = begin;
	auto begin_3     = begin;
	auto end_1       = end;
	auto end_2       = end;

	// Value placeholders

	Type   value;   // Any value
	size_t count;   // Any count


void algorithms()
{



		// ======================== //
		//						    //
		//		Algorithms !!!	    //
		//						    //
		// ======================== //




	{
		// For each

		auto unary_op_copy = std::for_each  (begin, end  , unary_op);
		auto unary_op_copy = std::for_each_n(begin, count, unary_op);
		// Calls 'unary_op(element)' for each element in the container
		// Returns the used unary_op  (a copy, original is not modified)
		// Complexity: N

		// For ordinary ranged loops, just use:
		for (auto& element : container);
	}

	{
		// Count

		auto count = std::count   (begin, end, value     );  // (1)
		auto count = std::count_if(begin, end, unary_pred);  // (2)
		// Counts appearances of
		// Returns count
		// (1)            element  == value
		// (2) unary_pred(element) == true 
		// Complexity: N
	}

	{
		// min/max element

		auto  min       = std::min_element   (begin, end);
		auto  min       = std::min_element   (begin, end, comp);
		auto       max  = std::   max_element(begin, end);
		auto       max  = std::   max_element(begin, end, comp);
		auto [min, max] = std::minmax_element(begin, end);
		auto [min, max] = std::minmax_element(begin, end, comp);
		// Finds the smallest/greatest element in a range
		// Returns iterator to element
		// minmax returns pair
		// Complexity: N
	}

	{
		// Find

		auto iterator = std::find       (begin, end, value     ); // (1)
		auto iterator = std::find_if    (begin, end, unary_pred); // (2)
		auto iterator = std::find_if_not(begin, end, unary_pred); // (3)
		// Finds first matching element
		// Returns iterator to matching element
		// (1)            element  == value 
		// (2) unary_pred(element) == true 
		// (2) unary_pred(element) == false 
		// Complexity: N
	}

	{
		// Search n

		auto iterator = std::search_n     (begin, end, count, value); 
		auto iterator = std::search_n     (begin, end, count, value, binary_pred);
		// Simillar to 'Find'
		// Finds first element where value appears 'count' times consecutively
		// Returns iterator to matching element
		// Complexity: N
	}

	{
		// Search

		auto iterator = std::search       (begin_1, end_1, begin_2, end_2);              // (1)
		auto iterator = std::search       (begin_1, end_1, begin_2, end_2, binary_pred);
		auto iterator = std::find_end     (begin_1, end_1, begin_2, end_2);              // (2)
		auto iterator = std::find_end     (begin_1, end_1, begin_2, end_2, binary_pred);
		// Simillar to 'Find'
		// Finds where range 2 is a subrange of 1
		// Returns iterator to first element where match is found
		// (1) find the first occurence
		// (2) find the last  occurence
		// Complexity: N
	}

	// DONT CONFUSSE  'find_end'  AND  'find_first_of'  !!!!!

	{
		// Find

		auto iterator = std::find_first_of(begin_1, end_1, begin_2, end_2);
		// Simillar to 'Find'
		// Finds first element in range 1 that also appears in range 2
		// Returns iterator to mathcing element
		// Complexity: N
	}

	{
		// Adjacent find

		auto iterator = std::adjacent_find(begin, end);
		auto iterator = std::adjacent_find(begin, end, binary_pred);
		// Finds first element followed by the same element
		// Simillar to 'seach_n' where value is anything and count is 2
		// Complexity: N
	}

	{
		// Is ...

		bool b = std::equal         (begin_1, end_2, begin_2);
		bool b = std::equal         (begin_1, end_2, begin_2, binary_pred);
		bool b = std::equal         (begin_1, end_2, begin_2, end_2);
		bool b = std::equal         (begin_1, end_2, begin_2, end_2, binary_pred);
		// Test if ranges are equal and in the same order
		// Complexity: N

		bool b = std::is_permutation(begin_1, end_2, begin_2); 
		bool b = std::is_permutation(begin_1, end_2, begin_2, binary_pred); 
		bool b = std::is_permutation(begin_1, end_2, begin_2, end_2); 
		bool b = std::is_permutation(begin_1, end_2, begin_2, end_2, binary_pred);
		// Test if ranges are equal (but not specifically in the same order)
		// Complexity: N^2   !!!

		bool b = std::is_sorted      (begin, end);
		bool b = std::is_sorted      (begin, end, comp);
		// Tests if range is sorted
		// Complexity: N

		bool b = std::is_heap        (begin, end);
		bool b = std::is_heap        (begin, end, comp);
		// Tests if range is heap
		// Complexity: N
	}
	
	//std::lexicographical_compare(begin_1, end_1, begin_2, end_2);
	
	{
		// mismatch
		auto iterator = std::is_sorted_until(begin, end);
		auto iterator = std::is_sorted_until(begin, end, comp);
		// Finds first element that isn't in sorted order
		// In other words
		// Finds end of sorted range
		// Complexity: N

		auto iterator = std::is_heap_until(begin, end);
		auto iterator = std::is_heap_until(begin, end, comp);
		// Finds first element that isn't in heap order
		// In other words
		// Finds end of heap range
		// Complexity: N

		auto [iterator_1, iterator_2] = std::mismatch(begin_1, end_1, begin_2);
		auto [iterator_1, iterator_2] = std::mismatch(begin_1, end_1, begin_2, binary_pred);
		auto [iterator_1, iterator_2] = std::mismatch(begin_1, end_1, begin_2, end_2);
		auto [iterator_1, iterator_2] = std::mismatch(begin_1, end_1, begin_2, end_2, binary_pred);
		// Finds first elements where ranges differ
		// Returns pair, iterators to first elements that aren't equal
		// Complexity: N
	}


	{
		// Has

		bool b = std::all_of (begin, end, unary_pred); // (1)
		bool b = std::any_of (begin, end, unary_pred); // (2)
		bool b = std::none_of(begin, end, unary_pred); // (3)
		// Tests the range
		// (1) all true
		// (2) one true
		// (3) all false
		// Complexity: N
	}

	{
		// Copy

		auto iterator = std::copy         (begin_1, end_1, begin_2);			 // (1)
		auto iterator = std::copy_backward(begin_1, end_1, begin_2);			 // (2)
		auto iterator = std::copy_n       (begin_1, count, begin_2);			 // (3)
		auto iterator = std::copy_if      (begin_1, end_1, begin_2, unary_pred); // (4)
		// Copies elements from range 1 to range 2
		// Returns end of destination range
		// (1) copy (from first to last)
		// (2) copy (from last to first)
		// (3) copy (from first to +count)
		// (4) copy (from first to last) only where   unary_pred(element) == true
		// Complexity: N
	}

	{
		// Move

		auto iterator = std::move         (begin_1, end_1, begin_2); // (1)
		auto iterator = std::move_backward(begin_1, end_1, begin_2); // (2)
		// Moves elements from range 1 to range 2
		// Returns end of destination range
		// (1) move (from first to last)
		// (2) move (from last to first)
		// Complexity: N
	}

	{
		// Transform

		auto iterator = std::transform(begin_1, end_1, begin_2, unary_op);			 // (1)
		auto iterator = std::transform(begin_1, end_1, begin_2, begin_3, binary_op); // (2)
		// Simillar to 'Copy' but applies operation first
		// Returns end of destination range
		// (1)  range_2 = unary_op(range_1)
		// (2)  range_3 = unary_op(range_1, range_2)
		// Complexity: N
	}

	{
		// Merge
		
		auto iterator = std::merge(begin_1, end_1, begin_2, end_2, begin_3);
		auto iterator = std::merge(begin_1, end_1, begin_2, end_2, begin_3, comp);
		// Merges two SORTED ranges
		// Returns end of destination range
		// Complexity: N
	}

	{
		// Swap

		auto iterator = std::swap_ranges(begin_1, end_1, begin_2);
		// Swaps every elements
		// Returns new end of range 2
		// Complexity: N
	}

	{
		// Fill

		(void)          std::fill      (begin, end  , value); // (1)
		auto iterator = std::fill_n    (begin, count, value); // (2)
		// Fills range with fixed value
		// Returns end of range 
		
		(void)          std::generate  (begin, end  , func ); // (1)
		auto iterator = std::generate_n(begin, count, func );	// (2)
		// Fill range with generated values
		// Returns end of range 

		(void)          std::iota      (begin, end  , value); // (1)
		// Fill range, starting from 'value', with incemented values.

		// Complexity: N
		// (1)  from first to last
		// (2)  from first to +count
	}


	{
		// Replace

		(void)          std::replace        (begin, end, value     , value); // (1)
		(void)          std::replace_if     (begin, end, unary_pred, value); // (2)
		// Replaces matching elements with the provided value

		auto iterator = std::replace_copy   (begin_1, end_1, begin_2, value     , value); // (1)
		auto iterator = std::replace_copy_if(begin_1, end_1, begin_2, unary_pred, value); // (2)
		// Same principle, but does so with a copy
		// Returns end of destination range 

		// Complexity: N
		// (1)             element  == value
		// (2)  unary_pred(element) == true
	}

	{
		// Reverse

		(void)          std::reverse     (begin  , end  );
		auto iterator = std::reverse_copy(begin_1, end_1, begin_2); // *
		// Reverses a range
		// * Does so with a copy
		// Returns end of destination range
		// Complexity: N
	}

	{
		// Rotate

		/* temporary */ auto new_begin = std::next(begin, count);

		auto iterator = std::rotate     (begin, new_begin, end);
		auto iterator = std::rotate_copy(begin, new_begin, end, begin); // *
		// Shifts a whole range, new_begin will be shifted to begin
		// elements shifted out of range will be rotated to the other end of the range
		// * Does so with a copy
		// Returns iterator to where the old begin is now shifted to.
		// Complexity: N
	}

	{
		// Permutation

		bool b = std::next_permutation(begin, end);
		bool b = std::prev_permutation(begin, end);
		// Rearanges range into a different permutation.
		// Whats a permutation? Imagine a set of trump cards. Any possible order of a deck is a permutation of this set of trump cards.
		// This algorithm will eventually have formed every posible order when called a lot of times.
		// Returns 'true' if a new permutation could be made
		// Complexity: N
	}

	{
		// Shuffle

		/* temporary */ std::default_random_engine rng{};

		(void) std::shuffle(begin, end, rng);
		// Moves elements and randomizes order
		// Shuffle requires a 'UniformRandomBitGenerator' in order to work.
		// Passing in 'rand' will not work. Nor will a lambda.
		// Complexity: N

		// A couple of URBGs in the standar library:
		std::default_random_engine{};	// Default random engine                          (usually mersenne twister)
		std::random_device{};			// Random engine using a physical random device   (if available, otherwise default_random_engine)
		// For specialized random devices:
		// [https://en.cppreference.com/w/cpp/header/random#predefined+generators]
		// Contains engines such as: minstd, mersenne, ranlux, knuth, ...

		// std::random_shuffle   has been removed from the language!
	}

	{
		// Partition

		auto iterator = std::partition       (begin, end, unary_pred);
		auto iterator = std::stable_partition(begin, end, unary_pred);
		// Partitions elements in a range
		// moves 'true' to the front, 'false' to the back
		// 'stable' will guarantee that the original relative order is preserved
		// Returns partition point
		// Complexity: N          (random acces iterator)
		// Complexity: N*log(N)   (other)

		auto [iterator_2, iterator_3] = std::partition_copy  (begin_1, end_1, begin_2, begin_3, unary_pred);
		// Simillar to 'Copy_if'
		// will copy 'true' to range 2, 'false' to range 3
		// Returns pair, end of both new ranges
		// Complexity: N
	}

	{
		// Test partition

		bool b        = std::is_partitioned (begin, end, unary_pred);
		// Tests if range is partitioned
		// Complexity: N

		auto iterator = std::partition_point(begin, end, unary_pred);
		// Finds partition point of PARTITIONED range
		// Complexity: log(N)
	}

	{
		// Sort

		/* temporary */ auto mid = std::next(begin  , count);

		(void)          std::sort             (begin  , end  );				    // (1)
		(void)          std::stable_sort      (begin  , end  );				    // (2)
		(void)          std::partial_sort     (begin  , end  , mid    );	    // (3)
		auto iterator = std::partial_sort_copy(begin_1, end_1, begin_2, end_2); // (4)
		(void)          std::nth_element      (begin  , mid  , end    );        // (5)
		// Sorts a range of elements
		// (1)  Default sort  (Quicksort)
		// (2)  Stable sort.  Guarantees original relative order to be preserved
		// (3)	Sorts range up to midpoint. Will also account for number after mid.
		// (4)  Same as above, but does so with a copy
		// Returns end of new range
		// (5)  Sorts only the exact number that would be found at mid, if the list were fully sorted. Elements before mid will be less than mid, elements after mid will be greated than mid.
		// Complexity:  N*log(N)
		// Complexity: (N*log(N))^2  (stable_sort) !!!
	}

	{
		// Heap

		(void) std::make_heap(begin, end);		  // (1)
		(void) std::push_heap(begin, end, value); // (2)
		(void) std::pop_heap (begin, end);		  // (3)
		(void) std::sort_heap(begin, end);		  // (4)
		// Performs heap operation
		// (1)  Moves elements and transforms range into a heap structure
		// (2)  Add a value to a heap structure. new heap structure will be [begin, end+1).
		// (3)  Removes the frontal element from a heap structure. I.e. moves it to the back of the range. Heap will now be [begin, end-1). 'end' will be the 'removed value'.
		// (4)	Transforms heap into a sorted range.
		// Complexity: N		(make_heap)
		// Complexity: log(N)	(push/pop_heap)
		// Complexity: N*log(N) (sort_heap)
	}

	{
		// Accumulate / Reduce

		auto result = std::accumulate(begin, end, value);			 // (1)
		auto result = std::accumulate(begin, end, value, binary_op); //  (2)
		auto result = std::reduce    (begin, end);					 // (1) *
		auto result = std::reduce    (begin, end, value);			 // (1)
		auto result = std::reduce    (begin, end, value, binary_op); //  (3)
		// Performs operation and takes result through the range
		// Returns result of operations
		// (1) Default behaviour is    result = result + element    where result starts with 'value' (or *0)
		// (2) Same principle, but using an other operation. Expects function of type   (result, element) -> result
		// (3) Same as above, but assumes that the operation is commutative
		// Complexity: N
	}

	{
		// Remove

		auto iterator = std::remove        (end  , end  , value     );			// (1)
		auto iterator = std::remove_if     (end  , end  , unary_pred);			// (2)
		auto iterator = std::remove_copy   (end_1, end_1, begin_2, value     );	// (3)
		auto iterator = std::remove_copy_if(end_1, end_1, begin_2, unary_pred); // (4)
		// Moves to-be-removed elements to the back. Returns 'end' of the new valid range.
		// !!! There is no guarantee that the elements in the back are still valid objects !!! (use partition instead)
		// Returns end of new range
		// (1)  Removes             element  == value
		// (2)  Removes  unary_pred(element) == true
		// (3)  Equal behaviour to 'copy_not   (begin, end, value     )'   (Hypothetically, doesn't actually exist)
		// (4)  Equal behaviour to 'copy_if_not(begin, end, unary_pred)'   (Hypothetically, doesn't actually exist)
		// This algorithms does not care about the the object that owns the range. To actually delete the elements, you'll have to call its erase function too.
		// Complexity: N
	}

	{
		// Unique

		auto iterator = std::unique     (begin  , end  );          // (1)
		auto iterator = std::unique_copy(begin_1, end_1, begin_2); // (2)
		// Simillar to 'Remove'
		// Returns end of new range
		// (1) Removes adjacent elements that appear more than once. Equal elements with a different one inbewteen don't get removed.
		// (2) Same, but does so with a copy
		// Complexity: N
	}

	{
		// Sample

		/* temporary */ std::default_random_engine rng{};

		auto iterator = std::sample(begin_1, end_1, begin_2, count, rng);
		// Sampled random elements from range 1, copies them to range 2
		// Same element could be sampled more than once
		// Returns new end of destination range
		// Complexity: N
	}

	{
		// Bound

		auto iterator = std::lower_bound(begin, end, value);		// (1)
		auto iterator = std::lower_bound(begin, end, value, comp); 
		auto iterator = std::upper_bound(begin, end, value);        // (2)
		auto iterator = std::upper_bound(begin, end, value, comp);
		// Finds element in a SORTED range
		// (1) first element not less    than value
		// (2) last  element not greater than value
		// Complexity: N

		auto [first, last] = std::equal_range(begin, end, value);
		auto [first, last] = std::equal_range(begin, end, value, comp);
		// Finds subrange where all elements equal value, in a SORTED range
		// Returns pair
		// [first, last) == value
	}

	{
		// Binary search

		bool b = std::binary_search(begin, end, value);
		bool b = std::binary_search(begin, end, value, comp);
		// Finds element in a SORTED range using a binary search
		// Complexity: log(N)
	}

	{
		// Merge

		/* temporary */ auto mid = std::next(begin, count);

		(void) std::inplace_merge(begin, mid, end);
		// Same as 'Merge'
		// But expects the consecutive [begin, mid) and [mid, end) to be the two SORTED ranges
		// Complexity: N
	}

	{
		// Includes

		bool b = std::includes(begin_1, end_1, begin_2, end_2);
		bool b = std::includes(begin_1, end_1, begin_2, end_2, comp);
		// Same as 'Search'
		// But expects a SORTED range instead
		// Complexity: log(N)
	}

	{
		// Lexicographical compare

		bool b = std::lexicographical_compare(begin_1, end_1, begin_2, end_2);
		bool b = std::lexicographical_compare(begin_1, end_1, begin_2, end_2, comp);
		// Compares the ranges lexicographically
		// 'char' type is compared lexicographically. Only ASCII
		// Other types will be compared like normal
		// Complexity: N
	}

	{
		// Set combination

		auto iterator = std::set_difference          (begin_1, end_1, begin_2, end_2, begin_3);				 // (1)
		auto iterator = std::set_difference          (begin_1, end_1, begin_2, end_2, begin_3, binary_pred);
		auto iterator = std::set_symmetric_difference(begin_1, end_1, begin_2, end_2, begin_3);				 // (2)
		auto iterator = std::set_symmetric_difference(begin_1, end_1, begin_2, end_2, begin_3, binary_pred);
		auto iterator = std::set_intersection        (begin_1, end_1, begin_2, end_2, begin_3);				 // (3)
		auto iterator = std::set_intersection        (begin_1, end_1, begin_2, end_2, begin_3, binary_pred);
		auto iterator = std::set_union               (begin_1, end_1, begin_2, end_2, begin_3);				 // (4)
		auto iterator = std::set_union               (begin_1, end_1, begin_2, end_2, begin_3, binary_pred);
		// Combines SORTED sets of data. Simillar to SQL database grouping
		// Returns new end iterator of the destination range.
		// (1)  Copies elements from range 1, not present in range 2, to range 3								|   1 2  :  2 3  ->  1
		// (2)  Copies elements, present only once in either range 1 and 2, to range 3							|   1 2  :  2 3  ->  1 3
		// (3)  Copies elements from range 1, also present in range 2, to range 3								|   1 2  :  2 3  ->  2
		// (4)  Copies all elements to range 3, if element is present in both sets, only one is copied.			|   1 2  :  2 3  ->  1 2 3
		// (4) is simillar to 'merge', But is different in the way that it only copies matching elements once

		// Small tip: use 'insert_iterator' with a 'set' because you probably don't know the size of the resulting set
	}

#if (__cplusplus >= 202002L)

	// C++20

	{
		// Shift

		auto iterator = std::shift_right(begin, end, count); // (1)
		auto iterator = std::shift_left (begin, end, count); // (2)
		// Shifts elements in range
		// Elements shifted out of range are gone
		// Elements shifted into range are unspecified
		// (1) Right    New 'begin' is returned
		// (2) Left     New 'end'   is returned
		// Complexity: N
	}

	{
		// Lexicographical compare three way

		int result = std::lexicographical_compare_three_way(begin_1, end_1, begin_2, end_2);
		// Compares the ranges lexicographically. Three way
		// result is:
		//   less < 0    equal == 0   greater > 0
		// Simillar to 'strcmp'
		// Complexity: N
	}
#endif
	

}

void helpful()
{

	{
		// Printing a range

		// Use an ostream_iterator

		std::ostream_iterator<Type> os_it{ std::cout, ", " };
		std::copy(begin, end, os_it);
	}

	{
		// Copy a range, but you don't know the final size

		// Use an insert_iterator

		std::insert_iterator inserter{ container, std::end(container) };
		std::copy(begin, end, inserter);
	}

}