#pragma once
#include "common/lang/string.h"
#include "common/lang/vector.h"
#include "sql/stmt/stmt.h"
class Db;
/**
 * @brief É¾³ý±íµÄÓï¾ä
 * @ingroup Statement
 */
class DropTableStmt : public Stmt
{
public:
	DropTableStmt( const std::string &table_name )
        : table_name_( table_name )
	{}
	
	virtual ~DropTableStmt() = default;

	StmtType type() const override { return StmtType::DROP_TABLE; }

	const std::string &table_name() const { return table_name_; }

	static RC create( Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt );

private:
	std::string table_name_;
};