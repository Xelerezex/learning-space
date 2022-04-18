#pragma once

#include <utility>

namespace RAII
{


template<typename Provider>
class Booking
{
    private:
        using BookingId = typename Provider::BookingId;

        Provider* provider;
        BookingId id;
    public:
        Booking(Provider* p, BookingId& c)
            : provider(p)
            , id(c)
        {
        }

        Booking(const Booking&) = delete;
        Booking(Booking&& other)
            : provider(other.provider)
            , id(other.id)
        {
            other.provider = nullptr;
        }
        Booking& operator = (const Booking&) = delete;

        Booking& operator = (Booking&& other)
        {
            std::swap(provider, other.provider);
            std::swap(id,       other.id);
            return *this;
        }


        ~Booking()
        {
            if (provider != nullptr)
            {
                provider->CancelOrComplete(*this);
            }
        }
};

}
