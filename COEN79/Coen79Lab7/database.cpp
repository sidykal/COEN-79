// FILE: database.cpp
// CLASS implemented: database (see database.h for documentation)
//  Siddharth Kalidindi | SCU | CSEN | 2/29/24

// INVARIANT for the database ADT:
//   1. The items in the database are stored in a dynamic array, where each entry of the array includes
//      a company name, a pointer to the head of the linked list of products, and a
//      a pointer to the tail of the linked list of products
//   2. The number of slots in the array of companies is stored in member varibale aloc_slots
//   3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"


//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif


namespace coen79_lab7
{
    
    database::database(const size_type& initial_capacity) {
        used_slots = 0;
        aloc_slots = initial_capacity;
        company_array = new company[aloc_slots];
    }
    
    
    database::database(const database &src) {
        Debug("Copy constructor..." << std::endl);
	aloc_slots = src.aloc_slots;
	used_slots = src.used_slots;
	company_array = new company[src.aloc_slots];
	*company_array = *src.company_array;
    }
    
    
    database& database::operator= (const database &rhs) {
        Debug("Assignment operator..." << std::endl);
        for(int i = 0; i < rhs.used_slots; ++i){
			this->company_array[i] = rhs.company_array[i];
	}
	this->aloc_slots = rhs.aloc_slots;
	this->used_slots = rhs.used_slots;
	std::cout << "copying elements of database...";
	return *this;
    }
    
    
    database::~database() {
        aloc_slots = 0;
	used_slots = 0;
	delete[] company_array;
    }
    
    
    void database::reserve(size_type new_capacity) {
        Debug("Reserve..." << std::endl);

        if(new_capacity == aloc_slots)
            return; // The allocated memory is already the right size.
        
        if(new_capacity < used_slots)
            new_capacity = used_slots; // Canít allocate less than we are using.
        
        company* new_company = new company[new_capacity];
	std::copy(company_array, company_array + used_slots, new_company);
	delete[] company_array;
	company_array = new_company;
	aloc_slots = new_capacity;
	return;
    }
    
    
    bool database::insert_company(const std::string &entry) {
        
        Debug("Insert company..." << std::endl);

        assert(entry.length() > 0);
        
        size_type pos = search_company(entry);
        
        // If you find a company that is false, because there are duplicates
        if(pos != COMPANY_NOT_FOUND) {
            return false;
        }
	else{
		company* insertion = new company(entry);
		if(used_slots < aloc_slots)
			company_array[used_slots] = *insertion;
		else{
			reserve(aloc_slots+1);
			company_array[used_slots] = *insertion;
		}
		used_slots++;
		return true;
	}
    }
    
    
    bool database::insert_item(const std::string &company, const std::string &product_name, const float &price) {
        Debug("Insert item..." << std::endl);

        assert(company.length() > 0 && product_name.length() > 0);

        if(search_company(company) >= 0){
		size_type i = search_company(company);
		company_array[i].insert(product_name, price);	
		return true;
	}
	else{
		return false;
	}
    }
    
    
    bool database::erase_company(const std::string &company) {
        
        size_type company_index = search_company(company);
        size_type i = search_company(company);
	if(i >= 0) {
		for(int j = company_index; j < used_slots-1; j++){
			company_array[i] = company_array[i+1];
		}
		used_slots--;
		return true;
	}
	return false;
    }
    
    
    bool database::erase_item(const std::string& cName, const std::string& pName) {
        
        assert(cName.length() > 0 && pName.length() > 0);

        size_type i = search_company(cName);
	if(i >= 0){
		company_array[i].erase(pName);
		return true;
	}
	return false;
    }
    
    
    
    database::size_type database::search_company(const std::string& company) {
        assert(company.length() > 0);
	
	size_type i;
	for(i = 0; i < used_slots; i++){
		if(company_array[i].get_name() == company){
			return i;
		}
	}
	return COMPANY_NOT_FOUND;
    }
    
    
    bool database::print_items_by_company(const std::string& cName) {
        assert(cName.length() > 0);

        size_type c_index = search_company(cName);
        
        if (c_index == COMPANY_NOT_FOUND) {
            return false;
        }
        
        std::cout << "Printing the products of " << cName << ":"<< std::endl;
        company_array[c_index].print_items();
        std::cout << std::endl;
        
        return true;
    }
    
    
    void database::print_companies() {
        
        std::cout << "Company List" << std::endl;
        for (int i = 0; i < used_slots; i++) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }
}

#endif
