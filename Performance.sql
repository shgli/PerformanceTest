/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "Performance" CASCADE;

CREATE TABLE "Performance" (
  "Algorithm" TEXT NOT NULL,
  "Implementation" TEXT NOT NULL,
  "ComputeStartTime" TIMESTAMP NOT NULL,
  "TotalTime" BIGINT NOT NULL,
  "UserTime" BIGINT NOT NULL,
  "SystemTime" BIGINT NOT NULL,
  "PercentTime" INTEGER NOT NULL,
  "NumOfCpu" INTEGER NOT NULL,
  "CacheSize" INTEGER NOT NULL,
  "HardwareConcurrency" INTEGER NOT NULL,
  "TotalMemory" INTEGER NOT NULL,
  "AvaiableMemory" INTEGER NOT NULL,
  "CPUName" TEXT NOT NULL,
  "IsDebug" BOOLEAN NOT NULL);

