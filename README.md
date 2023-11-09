# gertrude-cli
A CLI tool to make the creation of Makefiles easier!

# Prototype
gertrude DIRECTORY [ --var variable[=value] ]* rule-name [ --deps dependencies ] [ --cmd command ]*

# Commit norm
Commits to this project should follow a commit norm.
When adding a major feature, the commit should be a sentence, starting with "Gertrude now...", followed by a sentence that makes sense.

When adding minor features, files, or others, it should start with [ADD], and then the files' names or a description.

Modifications should start with [MOD], except when they're made on the "base" of Gertrude, in which case it should be a comprehensible sentencedescribing what exactly was modified.

Removed files or folders should be commited as [REMOVE] or [REM] followed by a file name or folder path.

You should do your best to make logical and small commits, but you can stack commits by naming them "[ADD] file1, file2, minor-feature1 [MOD] feature1, file1". Gertrude's base's changes should be pushed using their own commit.
