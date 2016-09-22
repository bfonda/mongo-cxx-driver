// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <chrono>
#include <cstdint>

#include <bsoncxx/document/view_or_value.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <mongocxx/options/find_one_common_options.hpp>
#include <mongocxx/stdx.hpp>

#include <mongocxx/config/prelude.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace options {

///
/// Class representing the optional arguments to a MongoDB find_and_modify replace operation
///
class MONGOCXX_API find_one_and_replace {
   public:
    /// Sets the collation for this operation.
    ///
    /// @param collation
    ///   The new collation.
    ///
    /// @see
    ///   https://docs.mongodb.com/manual/release-notes/3.3-dev-series-collation/#collation-option
    ///
    find_one_and_replace& collation(bsoncxx::document::view_or_value collation);

    ///
    /// Retrieves the current collation for this operation.
    ///
    /// @return
    ///   The current collation.
    ///
    /// @see
    ///   https://docs.mongodb.com/manual/release-notes/3.3-dev-series-collation/#collation-option
    ///
    const stdx::optional<bsoncxx::document::view_or_value>& collation() const;

    ///
    /// Whether or not to bypass document validation for this operation.
    ///
    /// @note
    ///   On servers >= 3.2, the server applies validation by default. On servers < 3.2, this option
    ///   is ignored.
    ///
    /// @param bypass_document_validation
    ///   Whether or not to bypass document validation.
    ///
    /// @see https://docs.mongodb.org/manual/core/document-validation/#bypass-document-validation
    ///
    find_one_and_replace& bypass_document_validation(bool bypass_document_validation);

    ///
    /// The current setting for bypassing document validation.
    ///
    /// @return the current bypass document validation setting.
    ///
    const stdx::optional<bool>& bypass_document_validation() const;

    ///
    /// Sets the maximum amount of time for this operation to run (server-side) in milliseconds.
    ///
    /// @param max_time
    ///   The max amount of time (in milliseconds).
    ///
    /// @see http://docs.mongodb.org/manual/reference/operator/meta/maxTimeMS
    ///
    find_one_and_replace& max_time(std::chrono::milliseconds max_time);

    ///
    /// The current max_time setting.
    ///
    /// @return the current max allowed running time (in milliseconds).
    ///
    /// @see http://docs.mongodb.org/manual/reference/operator/meta/maxTimeMS
    ///
    const stdx::optional<std::chrono::milliseconds>& max_time() const;

    ///
    /// Sets a projection, which limits the fields to return.
    ///
    /// @param projection
    ///   The projection document.
    ///
    /// @see http://docs.mongodb.org/manual/tutorial/project-fields-from-query-results/
    ///
    find_one_and_replace& projection(bsoncxx::document::view_or_value projection);

    ///
    /// Gets the current projection for this operation.
    ///
    /// @return The current projection.
    ///
    /// @see http://docs.mongodb.org/manual/tutorial/project-fields-from-query-results/
    ///
    const stdx::optional<bsoncxx::document::view_or_value>& projection() const;

    ///
    /// Set the desired version of the replaced document to return, either the original
    /// document, or the replacement. By default, the original document is returned.
    ///
    /// @param return_document
    ///   Version of document to return, either original or replaced.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    /// @see mongocxx::options::return_document
    ///
    find_one_and_replace& return_document(return_document return_document);

    ///
    /// Which version of the replaced document to return.
    ///
    /// @return Version of document to return, either original or replacement.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    /// @see mongocxx::options::return_document
    ///
    const stdx::optional<mongocxx::options::return_document>& return_document() const;

    ///
    /// Sets the order by which to search the collection for a matching document.
    ///
    /// @warning This can influence which document the operation modifies if the provided filter
    /// selects multiple documents.
    ///
    /// @param ordering
    ///   Document describing the order of the documents to be returned.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    ///
    find_one_and_replace& sort(bsoncxx::document::view_or_value ordering);

    ///
    /// Gets the current sort ordering.
    ///
    /// @return The current sort ordering.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    ///
    const stdx::optional<bsoncxx::document::view_or_value>& sort() const;

    ///
    /// Sets the upsert flag on the operation. When @c true, the operation creates a new document if
    /// no document matches the filter. When @c false, this operation will do nothing if there are
    /// no matching documents. The server-side default is false.
    ///
    /// @param upsert
    ///   Whether or not to perform an upsert.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    ///
    find_one_and_replace& upsert(bool upsert);

    ///
    /// Gets the current upsert setting.
    ///
    /// @return The current upsert setting.
    ///
    /// @see http://docs.mongodb.org/manual/reference/command/findAndModify/
    ///
    const stdx::optional<bool>& upsert() const;

   private:
    stdx::optional<bool> _bypass_document_validation;
    stdx::optional<bsoncxx::document::view_or_value> _collation;
    stdx::optional<std::chrono::milliseconds> _max_time;
    stdx::optional<bsoncxx::document::view_or_value> _projection;
    stdx::optional<mongocxx::options::return_document> _return_document;
    stdx::optional<bsoncxx::document::view_or_value> _ordering;
    stdx::optional<bool> _upsert;
};

}  // namespace options
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
