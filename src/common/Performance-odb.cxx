// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "Performance-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/no-id-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/no-id-object-result.hxx>

namespace odb
{
  // Performance
  //

  const char access::object_traits_impl< ::Performance, id_pgsql >::
  persist_statement_name[] = "Performance_persist";

  const char access::object_traits_impl< ::Performance, id_pgsql >::
  query_statement_name[] = "Performance_query";

  const char access::object_traits_impl< ::Performance, id_pgsql >::
  erase_query_statement_name[] = "Performance_erase_query";

  const unsigned int access::object_traits_impl< ::Performance, id_pgsql >::
  persist_statement_types[] =
  {
    pgsql::text_oid,
    pgsql::text_oid,
    pgsql::timestamp_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int8_oid,
    pgsql::int4_oid,
    pgsql::bool_oid
  };

  bool access::object_traits_impl< ::Performance, id_pgsql >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // Algorithm
    //
    if (t[0UL])
    {
      i.Algorithm_value.capacity (i.Algorithm_size);
      grew = true;
    }

    // Implementation
    //
    if (t[1UL])
    {
      i.Implementation_value.capacity (i.Implementation_size);
      grew = true;
    }

    // ComputeStartTime
    //
    t[2UL] = 0;

    // TotalTime
    //
    t[3UL] = 0;

    // UserTime
    //
    t[4UL] = 0;

    // SystemTime
    //
    t[5UL] = 0;

    // PercentTime
    //
    t[6UL] = 0;

    // IsDebug
    //
    t[7UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::Performance, id_pgsql >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // Algorithm
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i.Algorithm_value.data ();
    b[n].capacity = i.Algorithm_value.capacity ();
    b[n].size = &i.Algorithm_size;
    b[n].is_null = &i.Algorithm_null;
    n++;

    // Implementation
    //
    b[n].type = pgsql::bind::text;
    b[n].buffer = i.Implementation_value.data ();
    b[n].capacity = i.Implementation_value.capacity ();
    b[n].size = &i.Implementation_size;
    b[n].is_null = &i.Implementation_null;
    n++;

    // ComputeStartTime
    //
    b[n].type = pgsql::bind::timestamp;
    b[n].buffer = &i.ComputeStartTime_value;
    b[n].is_null = &i.ComputeStartTime_null;
    n++;

    // TotalTime
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.TotalTime_value;
    b[n].is_null = &i.TotalTime_null;
    n++;

    // UserTime
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.UserTime_value;
    b[n].is_null = &i.UserTime_null;
    n++;

    // SystemTime
    //
    b[n].type = pgsql::bind::bigint;
    b[n].buffer = &i.SystemTime_value;
    b[n].is_null = &i.SystemTime_null;
    n++;

    // PercentTime
    //
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i.PercentTime_value;
    b[n].is_null = &i.PercentTime_null;
    n++;

    // IsDebug
    //
    b[n].type = pgsql::bind::boolean_;
    b[n].buffer = &i.IsDebug_value;
    b[n].is_null = &i.IsDebug_null;
    n++;
  }

  bool access::object_traits_impl< ::Performance, id_pgsql >::
  init (image_type& i,
        const object_type& o,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // Algorithm
    //
    {
      ::std::string const& v =
        o.Algorithm;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.Algorithm_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i.Algorithm_value,
        size,
        is_null,
        v);
      i.Algorithm_null = is_null;
      i.Algorithm_size = size;
      grew = grew || (cap != i.Algorithm_value.capacity ());
    }

    // Implementation
    //
    {
      ::std::string const& v =
        o.Implementation;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.Implementation_value.capacity ());
      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_image (
        i.Implementation_value,
        size,
        is_null,
        v);
      i.Implementation_null = is_null;
      i.Implementation_size = size;
      grew = grew || (cap != i.Implementation_value.capacity ());
    }

    // ComputeStartTime
    //
    {
      ::boost::posix_time::ptime const& v =
        o.ComputeStartTime;

      bool is_null (false);
      pgsql::value_traits<
          ::boost::posix_time::ptime,
          pgsql::id_timestamp >::set_image (
        i.ComputeStartTime_value, is_null, v);
      i.ComputeStartTime_null = is_null;
    }

    // TotalTime
    //
    {
      ::uint64_t const& v =
        o.TotalTime;

      bool is_null (false);
      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_image (
        i.TotalTime_value, is_null, v);
      i.TotalTime_null = is_null;
    }

    // UserTime
    //
    {
      ::uint64_t const& v =
        o.UserTime;

      bool is_null (false);
      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_image (
        i.UserTime_value, is_null, v);
      i.UserTime_null = is_null;
    }

    // SystemTime
    //
    {
      ::uint64_t const& v =
        o.SystemTime;

      bool is_null (false);
      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_image (
        i.SystemTime_value, is_null, v);
      i.SystemTime_null = is_null;
    }

    // PercentTime
    //
    {
      ::uint32_t const& v =
        o.PercentTime;

      bool is_null (false);
      pgsql::value_traits<
          ::uint32_t,
          pgsql::id_integer >::set_image (
        i.PercentTime_value, is_null, v);
      i.PercentTime_null = is_null;
    }

    // IsDebug
    //
    {
      bool const& v =
        o.IsDebug;

      bool is_null (false);
      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_image (
        i.IsDebug_value, is_null, v);
      i.IsDebug_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::Performance, id_pgsql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // Algorithm
    //
    {
      ::std::string& v =
        o.Algorithm;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i.Algorithm_value,
        i.Algorithm_size,
        i.Algorithm_null);
    }

    // Implementation
    //
    {
      ::std::string& v =
        o.Implementation;

      pgsql::value_traits<
          ::std::string,
          pgsql::id_string >::set_value (
        v,
        i.Implementation_value,
        i.Implementation_size,
        i.Implementation_null);
    }

    // ComputeStartTime
    //
    {
      ::boost::posix_time::ptime& v =
        o.ComputeStartTime;

      pgsql::value_traits<
          ::boost::posix_time::ptime,
          pgsql::id_timestamp >::set_value (
        v,
        i.ComputeStartTime_value,
        i.ComputeStartTime_null);
    }

    // TotalTime
    //
    {
      ::uint64_t& v =
        o.TotalTime;

      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_value (
        v,
        i.TotalTime_value,
        i.TotalTime_null);
    }

    // UserTime
    //
    {
      ::uint64_t& v =
        o.UserTime;

      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_value (
        v,
        i.UserTime_value,
        i.UserTime_null);
    }

    // SystemTime
    //
    {
      ::uint64_t& v =
        o.SystemTime;

      pgsql::value_traits<
          ::uint64_t,
          pgsql::id_bigint >::set_value (
        v,
        i.SystemTime_value,
        i.SystemTime_null);
    }

    // PercentTime
    //
    {
      ::uint32_t& v =
        o.PercentTime;

      pgsql::value_traits<
          ::uint32_t,
          pgsql::id_integer >::set_value (
        v,
        i.PercentTime_value,
        i.PercentTime_null);
    }

    // IsDebug
    //
    {
      bool& v =
        o.IsDebug;

      pgsql::value_traits<
          bool,
          pgsql::id_boolean >::set_value (
        v,
        i.IsDebug_value,
        i.IsDebug_null);
    }
  }

  const char access::object_traits_impl< ::Performance, id_pgsql >::persist_statement[] =
  "INSERT INTO \"Performance\" "
  "(\"Algorithm\", "
  "\"Implementation\", "
  "\"ComputeStartTime\", "
  "\"TotalTime\", "
  "\"UserTime\", "
  "\"SystemTime\", "
  "\"PercentTime\", "
  "\"IsDebug\") "
  "VALUES "
  "($1, $2, $3, $4, $5, $6, $7, $8)";

  const char access::object_traits_impl< ::Performance, id_pgsql >::query_statement[] =
  "SELECT "
  "\"Performance\".\"Algorithm\", "
  "\"Performance\".\"Implementation\", "
  "\"Performance\".\"ComputeStartTime\", "
  "\"Performance\".\"TotalTime\", "
  "\"Performance\".\"UserTime\", "
  "\"Performance\".\"SystemTime\", "
  "\"Performance\".\"PercentTime\", "
  "\"Performance\".\"IsDebug\" "
  "FROM \"Performance\"";

  const char access::object_traits_impl< ::Performance, id_pgsql >::erase_query_statement[] =
  "DELETE FROM \"Performance\"";

  const char access::object_traits_impl< ::Performance, id_pgsql >::table_name[] =
  "\"Performance\"";

  void access::object_traits_impl< ::Performance, id_pgsql >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  result< access::object_traits_impl< ::Performance, id_pgsql >::object_type >
  access::object_traits_impl< ::Performance, id_pgsql >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        text,
        false,
        true,
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::no_id_object_result_impl<object_type> > r (
      new (shared) pgsql::no_id_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::Performance, id_pgsql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      erase_query_statement_name,
      text,
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
